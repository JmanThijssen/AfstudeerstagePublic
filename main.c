#include "project.h"
#include "eib_stk.h"
#include "MyUsart2USB.h"
#include "MyRealTimeClock.h"
#include "stm32f10x_rtc.h"
#include "system_stm32f10x.h"

/**
 * @brief The start of the application.
 * @details Here the hardware will be initialized.\n
 * The following functions get called:\n
 * - hwinit()\n
 * This function was made by Tapko to initialise hardware.
 * - usart2USB_Init()
 * - RTC_Initialise()
 * - SC_StackInit()\n
 * This function was made by Tapko to initialise the KNX stack.\n
 * .
 * Then SC_CyclicCalls() gets called in a loop.
 * @param none
 * @note SC_CyclicCalls() is a function that is part of Tapko's KAIstack.
 * @note This function was made by Tapko but is altered.
 */
int main(void)
{

	hwinit();

	usart2USB_Init();

	RTC_Initialise();

	SC_StackInit();

	WDG_START();

	while (_TRUE) {

		WDG_RESET();

		switch(SC_CyclicCalls()) {
		}
	}
}

