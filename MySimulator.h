#pragma once
#ifndef MYSIMULATOR_H
/// Include guard even though \#pragma once
#define MYSIMULATOR_H

#include "MyStorage.h"
#include <stdint.h>

enum dptListNumber {
	listDPT1 = 1,		///< 1; This value indicates something needs to happen with @ref dpt1list
	listDPT7 = 2,		///< 2; This value indicates something needs to happen with @ref dpt7list
	listDPT10 = 3,		///< 2; This value indicates something needs to happen with @ref dpt10list
	listDPT12 = 4,		///< 4; This value indicates something needs to happen with @ref dpt12list
	listDPT215 = 5,		///< 5; This value indicates something needs to happen with @ref dpt215list
	listDPT212 = 6,		///< 6; This value indicates something needs to happen with @ref dpt212list
	listDPT19 = 7,		///< 7; This value indicates something needs to happen with @ref dpt19list
	listDPT16 = 8		///< 8; This value indicates something needs to happen with @ref dpt16list
};

// Simulation
void startSimulation(const int16_t rtc_time,
		const unsigned char twoWeeksFlag);
unsigned char simulatePresence(const unsigned char nextList,
		const int16_t rtc_time);
void configureLocks(const int16_t rtc_time);
void clearLocks(const unsigned char simulating);
unsigned char calcNextList(void);
/*
 // Check for new input
 unsigned char CheckForUpdates(const unsigned char activeSimulation, const int16_t rtc_time,
 const unsigned char twoWeeksFlag);
 */
// Set bit 1 of locks
/*
 void unlockDPT1();
 void unlockDPT7();
 void unlockDPT10();
 void unlockDPT12();
 void unlockDPT215();
 void unlockDPT212();
 */
// Delete old stuff
/*
 * Note: Function should only be called when passed2Weeks is true
 */
void removeOldData(const short time);
void removeLastTime(const short maxValue);

#endif // MYSIMULATOR_H
