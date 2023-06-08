#include "MyUsart2USB.h"
#include "stm32f10x.h"  // target's register definitions
// include peripheral modules in stm32f10x_conf.h

extern dpt1_list* dpt1list;
extern dpt7_list* dpt7list;
extern dpt10_list* dpt10list;
extern dpt12_list* dpt12list;
extern dpt215_list* dpt215list;
extern dpt212_list* dpt212list;
extern dpt19_list* dpt19list;
extern dpt16_list* dpt16list;

///@cond
static void transmitDPT1_USB(void);
static void transmitDPT7_USB(void);
static void transmitDPT10_USB(void);
static void transmitDPT12_USB(void);
static void transmitDPT215_USB(void);
static void transmitDPT212_USB(void);
static void transmitDPT19_USB(void);
static void transmitDPT16_USB(void);
///@endcond

/**
 * @brief  Activate USART 2
 * @details Sets IO port A clock enable bit and Alternate function IO
 * clock enable bit in APB2 peripheral clock enable register.\n
 * Sets USART 2 clock enable bit in APB1 peripheral clock enable register.\n
 * Sets GPIO A2 as alternate function with push pull output (Tx).\n
 * Sets GPIO A3 as floating input (Rx).\n
 * Sets the baudrate to 9600.\n
 * Sets the wordlength to 8 bits.\n
 * Enables one stopbit.\n
 * Disables parity bits.\n
 * Disables hardware flow control.\n
 * Sets USART mode to Tx. So it won't check for incoming data.\n
 * The USART enable bit in USART2 control register 1 will be set.
 * @param  none
 */
void usart2USB_Init(void)
{
	// Rx = PA3
	// Tx = PA2
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* Enable peripheral clocks for USART2 on GPIOA */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA |
	RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	/* Configure PA2 and PA3 as USART1 TX/RX */

	/* PA2 = alternate function push/pull output */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* PA3 = floating input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure and initialize usart... */
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =
	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;

	USART_Init(USART2, &USART_InitStructure);

	/* Enable USART2 */
	USART_Cmd(USART2, ENABLE);
	// USART2->CR1 |= 0x2000; Is better for performance
}

/**
 * @brief  Deactivate USART 2.
 * @details The USART enable bit in USART2 control register 1 will be reset.
 * @param  none
 */
void usart2_Deinitialise(void)
{
	// Wait until Transmission is complete
	while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
		;
	USART_Cmd(USART2, DISABLE);
	// 0x2000 is USART2 enable bit
	// USART2->CR1 &= ~0x2000; Is better for performance
}

/**
 * @brief Transmit two bytes over USART 2.
 * @details The MSB of \p data will be sent over USART 2.\n
 * When the MSB is sent, the LSB will be sent.
 * @param data A value of two bytes that will be sent.
 * @pre USART2 needs to be initialized.
 */
void transmit2toUSB(const uint16_t data)
{
	// Wait until Transmit data register is empty
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
		;
	USART_SendData(USART2, data >> 8);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
		;
	USART_SendData(USART2, data & 0x00FF);
}

/**
 * @brief Transmit one byte over USART2.
 * @details \p data will be sent over USART2.
 * @param data Data to be transmitted.
 * @pre USART2 needs to be initialized.
 */
void transmit1toUSB(const uint8_t data)
{
	// Wait until Transmit data register is empty
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
		;
	USART_SendData(USART2, data);
}

/**
 * @brief Sends data of all lists over USART 2
 * @details The difference in time between the RTC time and the KNX time will be sent over USART 2.\n
 * Then all data stored in the lists will be sent over USART 2.\n
 * After each list "0 4" will be sent to indicate the list has been sent.
 * @param time_Diff The difference in time between KNX time and RTC time.
 * @pre USART2 needs to be initialized.
 */
void transmitAllToUSB(const int16_t time_Diff)
{
	transmit2toUSB(time_Diff);
	transmitDPT1_USB();
	transmitDPT7_USB();
	transmitDPT10_USB();
	transmitDPT12_USB();
	transmitDPT215_USB();
	transmitDPT212_USB();
	transmitDPT19_USB();
	transmitDPT16_USB();
}

// 1
/**
 * @brief Transmit the data within @ref dpt1list.
 * @details Transmits all data stored in dpt1list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT1_USB(void)
{
	const short size = dpt1SizeOfList(dpt1list);
	for (short i = 0; i < size; i++) {
		struct dpt1 first = dpt1FirstToLast(dpt1list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);
		transmit1toUSB(first.dat);
	}
	/*
	 * To show the end of dpt1list is reached, we will send EOT
	 * Since the End Of Transmission value can't be sent as time,
	 * A program checking the time for EOT will know that this is
	 * the entire dpt1list.
	 * (NUL followed by EOT)
	 */
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 2
/**
 * @brief Transmit the data within @ref dpt7list.
 * @details Transmits all data stored in dpt7list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT7_USB(void)
{
	const short size = dpt7SizeOfList(dpt7list);
	for (short i = 0; i < size; i++) {
		struct dpt7 first = dpt7FirstToLast(dpt7list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		transmit1toUSB(first.dat[0]);
		transmit1toUSB(first.dat[1]);
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 3
/**
 * @brief Transmit the data within @ref dpt10list.
 * @details Transmits all data stored in dpt10list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT10_USB(void)
{
	const short size = dpt10SizeOfList(dpt10list);
	for (short i = 0; i < size; i++) {
		struct dpt10 first = dpt10FirstToLast(dpt10list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		transmit1toUSB(first.dat[0]);
		transmit1toUSB(first.dat[1]);
		transmit1toUSB(first.dat[2]);
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 4
/**
 * @brief Transmit the data within @ref dpt12list.
 * @details Transmits all data stored in dpt12list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT12_USB(void)
{
	const short size = dpt12SizeOfList(dpt12list);
	for (short i = 0; i < size; i++) {
		struct dpt12 first = dpt12FirstToLast(dpt12list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		for (int n = 0; n < 4; n++) {
			transmit1toUSB(first.dat[n]);
		}
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 5
/**
 * @brief Transmit the data within @ref dpt215list.
 * @details Transmits all data stored in dpt215list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT215_USB(void)
{
	const short size = dpt215SizeOfList(dpt215list);
	for (short i = 0; i < size; i++) {
		struct dpt215 first = dpt215FirstToLast(dpt215list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		// Even though this for loop is worse for performance, it is more readable.
		for (int n = 0; n < 5; n++) {
			transmit1toUSB(first.dat[n]);
		}
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 6
/**
 * @brief Transmit the data within @ref dpt212list.
 * @details Transmits all data stored in dpt212list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized
 */
static void transmitDPT212_USB(void)
{
	const short size = dpt212SizeOfList(dpt212list);
	for (short i = 0; i < size; i++) {
		struct dpt212 first = dpt212FirstToLast(dpt212list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		// Even though this for loop is worse for performance, it is more readable.
		for (int n = 0; n < 6; n++) {
			transmit1toUSB(first.dat[n]);
		}
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 8
/**
 * @brief Transmit the data within @ref dpt19list
 * @details Transmits all data stored in dpt19list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT19_USB(void)
{
	const short size = dpt19SizeOfList(dpt19list);
	for (short i = 0; i < size; i++) {
		struct dpt19 first = dpt19FirstToLast(dpt19list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		// Even though this for loop is worse for performance, it is more readable.
		for (int n = 0; n < 8; n++) {
			transmit1toUSB(first.dat[n]);
		}
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}

// 14
/**
 * @brief Transmit the data within @ref dpt16list.
 * @details Transmits all data stored in dpt16list.\n
 * When all data is transmitted it will send 0 4 to indicate the list is transmitted.
 * @param none
 * @pre USART2 needs to be initialized.
 */
static void transmitDPT16_USB(void)
{
	const short size = dpt16SizeOfList(dpt16list);
	for (short i = 0; i < size; i++) {
		struct dpt16 first = dpt16FirstToLast(dpt16list);
		// Make sure time does not contain EOT
		if (0x0004 == first.time) {
			transmit2toUSB(0xFFFF);
		}
		else {
			transmit2toUSB(first.time);
		}
		transmit2toUSB(first.grpAd);

		// Even though this for loop is worse for performance, it is more readable.
		for (int n = 0; n < 14; n++) {
			transmit1toUSB(first.dat[n]);
		}
	}
	transmit2toUSB(0x0004);		// EOT = 0x0004
}
