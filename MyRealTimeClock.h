#pragma once
#ifndef MYREALTIMECLOCK_H
/// Include guard even though \#pragma once
#define MYREALTIMECLOCK_H

/// @brief If TEST_FASE is defined the RTC will behave different.
/// @details 5 seconds will be counted as 1 minute and the alarm will be set to 1 minute.
#define TEST_FASE

#include <stdint.h>

//unsigned short RTC_time = 0;

/*
 * This initializes the RTC
 * During initialization the time will be set according to the parameters
 * 	Set HSE as clock source
 * 	Enter Configuration mode
 * 	Enable interrupts on alarm
 * 	Set the prescaler
 * 	Set the alarm value
 * 	Leave Configuration mode
 * 	Wait until synchronized
 */
void RTC_Initialise();

/*
 * This function sets the time of the RTC according to the parameters
 * This function does take the day into account
 */
void RTC_SetTime(const int16_t rtc_time);

/*
 * This function sets the time of the RTC according to the parameters
 * This function will not take the day into account
 */
void RTC_SetTime_hm(const char hours, const char minutes);

/*
 * This function returns the count value divided by 60000
 * This value is equal to the number of minutes since the counter was set to 0
 */
int16_t RTC_GetTime();

/*
 * This function converts the time in hours and minutes to the count value
 * This conversion does not check for days
 */
uint32_t RTC_TimeToCount(const char hours, const char minutes);

/*
 * This function converts the rtc time to a rtc counter value
 */
uint32_t RTC_RTCToCount(const int16_t rtc_time);

/*
 * This function calculates the time difference between the actual time and the RTC time
 */
int16_t calcTimeDifference(const uint16_t knx_time_DHM,
		const int16_t rtc_time);

#endif // MYREALTIMECLOCK_H
