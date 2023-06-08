#include "MyRealTimeClock.h"
#include <stm32f10x_rtc.h>
#include <stm32f10x_conf.h>
#include <stm32f10x_it.h>

/**
 * @brief Enables the Real Time Clock.
 * @details Sets the Power interface clock enable bit and the Backup interface clock bit.\n
 * Enables access to the RTC and backup registers.\n
 * Forces the backup domain reset.\n
 * Releases the backup domain reset.\n
 * Waits until External high-speed clock ready flag is set in Clock control register.\n
 * Sets HSE clock divided by 128 as RTC clock.\n
 * Sets the configuration flag in RTC control register low.\n
 * Sets the RTC prescaler load registers to 124.\n
 * (HSE clock/128 = RTC clock source; RTC clock source / (124+1) = 1 kHz)\n
 * Sets the RTC alarm registers to the equivalent of two weeks.\n
 * (2 weeks = 14 days = 14*24 hours = 14*24*60 minutes = 14*24*60*60 s = 14*24*60*60 ms)\n
 * Resets the configuration flag in RTC control register low.\n
 * Enables the RTC.\n
 * Clears the Registers synchronized flag in RTC control register low.\n
 * Waits until the Registers synchronized flag is set.
 * @param none
 */
void RTC_Initialise()
{
	// Enable clock for backup interface and power interface
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP,
			ENABLE);

	PWR_BackupAccessCmd(ENABLE);

	RCC_BackupResetCmd(ENABLE);
	RCC_BackupResetCmd(DISABLE);

	// Enable HSE as clock source for RTC

	// wait till HSE is ready
	while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET)
		;

	// Select HSE as Clock Source
	RCC_RTCCLKConfig(RCC_RTCCLKSource_HSE_Div128);

	RTC_EnterConfigMode();

	/* Set RTC Prescaler Load (PRL) to 124
	 * Because:
	 * Frtcclk = HSE/128 = 16MHz/128 = 125kHz
	 * Ftr_clk = Frtcclk/(PRL+1)
	 * Ftr_clk = 125kHz/(124+1) = 125kHz/125 = 1kHz
	 * This gives the RTC an accuracy of 1ms (Which is far more than we need)
	 *
	 * Clear first bits of Prescaler
	 * RTC->PRLH = 124 >> 16 & 000F
	 * Set last bits of Prescaler
	 * RTC->PRLL |= 124
	 */
	RTC->PRLH = (124 >> 16) & 0x000F;
	RTC->PRLL = 124;
#ifndef TEST_FASE
	/* Set RTC Alarm value
	 * This value will be set to 14 days
	 * 1000						= 1 sec
	 * 1000 	* 	60 	= 60k	= 1 minute
	 * 60k 		* 	60 	= 3600k	= 1 hour
	 * 3600k	*	24	= 86.4M = 1 day
	 * 86.4M	*	14	= 1209.6M	= 14 days	= 0x48190800
	 *
	 * RTC->ALRH = 0x4819	// 0x48190800 >> 16;
	 * RTC->ALRL = 0x0800	// 0x48190800 & 0xFFFF;
	 */
	RTC->ALRH = 0x4819;
	RTC->ALRL = 0x0800;
#else // TEST_FASE
	/* Set RTC Alarm value
	 * This value will be set to 5 minutes						// 30 seconds
	 * 1000						= 1 sec							// 1000 * 30 = 30k = 30 sec
	 * 1000 	* 	60 	= 60k	= 1 minute						// 60 seconds
	 * 60k		*	5	= 300k	= 5 minutes		= 0x000493E0	// 1000 * 60 = 60k = 1 min
	 *
	 * RTC->ALRH = 0x0004	// 0x000493E0 >> 16
	 * RTC->ALRL = 0x93E0	// 0x000493E0 & 0xFFFF
	 */
	RTC->ALRH = /*0x0004*/0x0000;
	RTC->ALRL = /*0x93E00x7530*/0xEA60;
#endif // TEST_FASE
	RTC_ExitConfigMode();
	RCC_RTCCLKCmd(ENABLE);

	RTC_WaitForSynchro();
}

/**
 * @brief Sets the RTC time
 * @details Converts the RTC time format value to the actual
 * counter value using RTC_RTCToCount().\n
 * Splits the converted value in two words.\n
 * Waits until RTC operation OFF flag is set.\n
 * Sets the configuration flag in RTC control register low.\n
 * Waits until RTC operation OFF flag is set.\n
 * Sets the RTC counter registers.\n
 * Waits until RTC operation OFF flag is set.\n
 * Resets the configuration flag in RTC control register low.\n
 * Waits until RTC operation OFF flag is set.\n
 * Clears the Registers synchronized flag in RTC control register low.\n
 * Waits until the Registers synchronized flag is set.
 * @param[in] rtc_time Time value according to the RTC time format.
 * @pre RTC must be initialized.
 */
void RTC_SetTime(const int16_t rtc_time)
{
	const int32_t conv_time = RTC_RTCToCount(rtc_time);
	const uint16_t countHigh = conv_time >> 16;
	const uint16_t countLow = conv_time & 0xFFFF;

	/* Enter Configuration Mode
	 * RTC->CRL |= CNF
	 * RTC->CRL |= 0x0010
	 */
	/* Just to make sure this function is not called
	 * to fast after anther operation.
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC_EnterConfigMode();

	/* Set MSBs of counter
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC->CNTH = countHigh;

	/* Set LSBs of counter
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC->CNTL = countLow;

	/* Leave Configuration mode
	 * RTC->CRL &= ~CNF			// CoNfiguration Flag
	 * RTC->CRL &= ~0x0010
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC_ExitConfigMode();
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC_WaitForSynchro();
}

/**
 * @brief Sets the RTC time
 * @details Converts the parameters in an actual counter value using RTC_TimeToCount().\n
 * Splits the converted value in two words.\n
 * Waits until RTC operation OFF flag is set.\n
 * Sets the configuration flag in RTC control register low.\n
 * Waits until RTC operation OFF flag is set.\n
 * Sets the RTC counter registers.\n
 * Waits until RTC operation OFF flag is set.\n
 * Resets the configuration flag in RTC control register low.\n
 * Waits until RTC operation OFF flag is set.\n
 * Clears the Registers synchronized flag in RTC control register low.\n
 * Waits until the Registers synchronized flag is set.
 * @param[in] hours Time in hours.
 * @param[in] minutes Time in minutes.
 */
void RTC_SetTime_hm(const char hours, const char minutes)
{

	int32_t conv_time = RTC_TimeToCount(hours, minutes);
	uint16_t countHigh = conv_time >> 16;
	uint16_t countLow = conv_time & 0xFFFF;

	/* Enter Configuration Mode
	 * RTC->CRL |= CNF
	 * RTC->CRL |= 0x0010
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC_EnterConfigMode();

	/* Set MSBs of counter
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC->CNTH = countHigh;

	/* Set LSBs of counter
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC->CNTL = countLow;

	/* Leave Configuration mode
	 * RTC->CRL &= ~CNF
	 * RTC->CRL &= ~0x0010
	 */
	while (0x0020 != (RTC->CRL & 0x0020)) {
		;
	}
	RTC_ExitConfigMode();
	while (0x0020 == (RTC->CRL & 0x0020)) {
		;
	}
	RTC_WaitForSynchro();
}

/**
 * @brief Gets the RTC time
 * @details Reads the RTC counter registers.\n
 * Converts the RTC counter registers value to a RTC time format value.\n
 * returns the RTC time format value.
 * @param none
 * @returns The time In RTC time format.
 * @pre RTC must be initialized, otherwise the return value will have no meaning.
 * @pre Counter registers should be reset before max value was reached otherwise
 * this function may return wrong results (since counter value may be too high).
 */
int16_t RTC_GetTime()
{
	uint32_t time = 0;

	time = RTC->CNTH << 16;
	time += RTC->CNTL;
#ifdef TEST_FASE
	time = time / 5000;
#else
	time = time / 60000;
#endif // TEST_FASE
	return time;
}

/**
 * @brief Converts parameters to RTC counter format value
 * @details Converts the hours and minutes to a RTC counter format value.
 * @param[in] hours Time in hours.
 * @param[in] minutes Time in minutes.
 * @returns The time in RTC counter format.
 */
uint32_t RTC_TimeToCount(const char hours, const char minutes)
{
	// 3600000 ms in one hour
	int32_t conv_time = hours * 3600000;
	// 60000 ms in one minute
	conv_time += minutes * 60000;
	return conv_time;
}

/**
 * @brief Converts the time to a RTC counter format value.
 * @details Convertst the time in RTC time format to a RTC counter format value.
 * @param[in] rtc_time Time in RTC time format.
 * @returns The time in RTC counter format.
 */
uint32_t RTC_RTCToCount(const int16_t rtc_time)
{
#ifdef TEST_FASE
	return rtc_time * 5000;
#else
	/*
	 * RTC time format is number of minutes
	 * while RTC counter value is number of ms.
	 * There are 60000 ms in one minute.
	 */
	return rtc_time * 60000;
#endif // TEST_FASE
}

/**
 * @brief Calculates the time difference between the actual time and the RTC time
 * @details Converts \p knx_time_DHM to three values: day, hour and minute.\n
 * If day is zero, the day value was invalid.\n
 * If day is invalid (0) the \p rtc_time will be converted
 * to a value only containing hours and minutes.\n\n
 * The values day, hour and minute will be converted to a time value with RTC time format.\n
 * \p rtc_time is already in this format so now we can
 * subtract the converted time from \p rtc_time.\n\n
 * However since we would like to calculate an unsigned integer,
 * the result of the subtraction will be converted to a unsigned integer.\n
 * To do so, it will check if the result is smaller than 0.\n\n
 * If the result is smaller than 0 the result will be added to 0x2760.
 * Then the result of this addition will be returned.\n\n
 * If the result is not smaller than 0, the result will be returned.
 * @param[in] knx_time_DHM The current actual time (the two MSB's of a KNX message)
 * @param[in] rtc_time The current RTC time (in RTC time format)
 * @returns The difference in time in RTC time format (with range: 0 <= difference < 7 days)
 * @note 0x2760 is the RTC time value for one week.\n
 * Since adding a negative value to it, it will subtract the absolute value from 0x2760.
 */
int16_t calcTimeDifference(const uint16_t knx_time_DHM,
		const int16_t rtc_time)
{
	char day = knx_time_DHM >> 13;
	char hour = (knx_time_DHM >> 8) % 32;
	char minute = (knx_time_DHM << 8) >> 8;
	int16_t currTime = rtc_time;
	int16_t timeDifference = 0;

	// Convert day, hour and minute to RTC time format
	int16_t knx_time_RTC = hour * 60;

	knx_time_RTC += minute;
	if (0 == day) {
		// day value is not valid
		// So we compare rtc_time without day as well
		currTime = currTime % 0x05A0;			// 0x05A0 = 1 day
	}
	else {
		// day value is valid
		// Since day 1 in RTC is 0 and day 1 in knx is 1:
		//	We have to subtract 1 from the day value
		knx_time_RTC += (day - 1) * 60 * 24;

		// Make sure we compare day with values of week 1
		if (currTime >= 0x2760) {				// 0x2760 = 1 week
			currTime -= 0x2760;
		}
	}

	timeDifference = currTime - knx_time_RTC;

	// make sure the difference is a positive value
	if (timeDifference < 0) {
		// if time is negative we have to make sure it stays in range of one week
		timeDifference += 0x2760;		// 0x2760 = 1 week
	}

	return timeDifference;
}
