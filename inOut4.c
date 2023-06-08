//------------------------------------------------------------------
//
// Copyright (c) 1999 - 2009 Tapko Technologies GmbH
//
// PROPRIETARY RIGHTS of Tapko Technologies GmbH are involved
// in the subject matter of this material. All manufacturing,
// reproduction, use, and sales rights pertaining to this subject matter
// are governed by the license agreement. The recipient of this software
// implicitly accepts the terms of the license.
//
// This file is part of the Libraries of Tapko Technologies GmbH
// (e.g. TAPKO EIB/KNX Communication Stack)
//
//------------------------------------------------------------------
// $HeadURL: https://tapko-app:1443/svn/KAIstack/branches/KAIstack_branches/KAI_securityBranch/appl_example/inOut4/src/inOut4.c $
//
// Project:           EIB-Communication-Stack
//
// $Author: Zivkovic_z $
//
// $Date: 2016-10-04 10:30:50 +0200 (Di, 04 Okt 2016) $
// $Revision: 3125 $
//------------------------------------------------------------------
#ifdef DoxyForKAIStack
///@addtogroup KAI_EXAMPL_4io
///@{
#endif // DoxyForKAIStack

#include "project.h"
#include "eib_stk.h"
#include "app.h"
#include EIB_DEVICE_MODEL_APP_H_FILE

#include "MyStorage.h"
#include "MyRealTimeClock.h"
#include "MyUsart2USB.h"
#include "MySimulator.h"

/**
 * @defgroup list List declaration
 * @brief This pointer points to a @ref dptX_list "list" of @ref dptX_node "dptX_nodes".
 * @details This is a global variable that is defined in inOut4.c.\n
 * It is declared as extern in MySimulator.c and MyUsart2USB.c.
 * @note The declarations are in the .c files to make sure that the access
 * to this variable is limited.\n If it were in a header file, all files
 * that include that header file would have access to this variable.
 * @{
 */

/**
 * @{
 * @name dptXlist
 * @brief This pointer points to a @ref dptX_list "list" of @ref dptX_node "nodes".
 */
/// @brief This pointer points to a @ref dpt1_list of @ref dpt1_node "dpt1_nodes".
dpt1_list* dpt1list;

/// @brief This pointer points to a @ref dpt7_list of @ref dpt7_node "dpt7_nodes".
dpt7_list* dpt7list;

/// @brief This pointer points to a @ref dpt10_list of @ref dpt10_node "dpt10_nodes".
dpt10_list* dpt10list;

/// @brief This pointer points to a @ref dpt12_list of @ref dpt12_node "dpt12_nodes".
dpt12_list* dpt12list;

/// @brief This pointer points to a @ref dpt215_list of @ref dpt215_node "dpt215_nodes".
dpt215_list* dpt215list;

/// @brief This pointer points to a @ref dpt212_list of @ref dpt212_node "dpt212_nodes".
dpt212_list* dpt212list;

/// @brief This pointer points to a @ref dpt19_list of @ref dpt19_node "dpt19_nodes".
dpt19_list* dpt19list;

/// @brief This pointer points to a @ref dpt16_list of @ref dpt16_node "dpt16_nodes".
dpt16_list* dpt16list;
///@}
///@}

extern unsigned char dpt1Lock, dpt7Lock, dpt10Lock, dpt12Lock,
    dpt215Lock, dpt212Lock, dpt19Lock, dpt16Lock;

unsigned char CheckForUpdates(const unsigned char activeSimulation, const int16_t rtc_time,
		const unsigned char twoWeeksFlag);

#ifdef DoxyForKAIStack
/**@page KAI_EXAMPL_4io Example 4 Input, 4 Output
##Location

This example is located at:
  appl_example/inOut4

##General

The echo example is a small application which shows the usage of
- group object communication

##General

The echo example is a small application which shows simple in and outputs.

##Functionality

When pressing on of the 4 push buttons on the evaluation board, the object value is changed and sent on the bus.
The LEDs are updated on the other 4 communication object.

##Source Files

| | |
| |-|
| @ref inOut4/src/app_data.c "app_data.c" | contains the definition of the constant data (tables and parameter) of the application 
| @ref inOut4/src/inOut4.c "inOut4.c"     | contains the application code
| @ref inOut4/src/main.c "main.c"         | contains the main
| @ref inOut4/src/app.h "app.h"           | contains the declaration of variables, constants ..
| @ref inOut4/src/cotab.h "cotab.h"       | contains the definition of the communication objects and addresses
| @ref inOut4/src/project.h "project.h"   | contains the settings of KAIstack

##ETS database

@note Please set your target and device model in project.h	.

*/

/**
@example inOut4/src/app.h
This file is part of @ref KAI_EXAMPL_4io 

@example inOut4/src/cotab.h 
This file is part of @ref KAI_EXAMPL_4io 

@example inOut4/src/project.h 
This file is part of @ref KAI_EXAMPL_4io 

@example inOut4/src/app_data.c 
This file is part of @ref KAI_EXAMPL_4io 

@example inOut4/src/inOut4.c 
This file is part of @ref KAI_EXAMPL_4io 

@example inOut4/src/main.c 
This file is part of @ref KAI_EXAMPL_4io 

@}

*/
#endif // DoxyForKAIStack

#ifndef BITF
/**
 * @name Bit conversions
 * @brief The value of a bit.
 * @details Converts BIT[number] to the value of that bit if it were set.
 */
/// @details 2^0 = 1 = 0x00001
  #define BIT0 0x00001
/// @details 2^1 = 2 = 0x00002
  #define BIT1 0x00002
/// @details 2^2 = 4 = 0x00004
  #define BIT2 0x00004
/// @details 2^3 = 8 = 0x00008
  #define BIT3 0x00008
/// @details 2^4 = 16 = 0x00010
  #define BIT4 0x00010
/// @details 2^5 = 32 = 0x00020
  #define BIT5 0x00020
/// @details 2^6 = 64 = 0x00040
  #define BIT6 0x00040
/// @details 2^7 = 128 0x00080
  #define BIT7 0x00080

/// @details 2^8 = 256 = 0x00100
  #define BIT8 0x00100
/// @details 2^9 = 512 = 0x00200
  #define BIT9 0x00200
/// @details 2^10 = 1024 = 0x00400
  #define BITA 0x00400
/// @details 2^11 = 2048 = 0x00800
  #define BITB 0x00800
/// @details 2^12 = 4096 = 0x01000
  #define BITC 0x01000
/// @details 2^13 = 8192 = 0x02000
  #define BITD 0x02000
/// @details 2^14 = 16384 = 0x04000
  #define BITE 0x04000
/// @details 2^15 = 32768 = 0x08000
  #define BITF 0x08000
///@}
#endif // BITF

//------------------------------------------------------------------
// global RAM variables
//------------------------------------------------------------------
/**
 * @brief An array which converts the index number to a value of that bit if it were set.
 * @details Only works for 0 to 7 (since there are 8 bits in a byte).
 * @note This array was made by Tapko for an example program.
 */
unsigned const maskArray[8]  = {BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7}; 

//------------------------------------------------------------------
/**
 * @brief Turns a LED on or off.
 * @details Calls KSD_SetUserLEDval() with \p nr and \p val as the
 * parameters.\n
 * @param[in] nr Number of the LED to be turned on as described on the
 * development board.
 * @param[in] val New value of the LED (0 for OFF and 1 for ON).
 * @note This function was made by Tapko for an example porgram.
 */
void SetLed(unsigned char nr, unsigned char val)
{
	KSD_SetUserLEDval(nr, val);
//  KSD_SwitchUserLED(((unsigned int) val) << nr, maskArray[nr]);
}

//------------------------------------------------------------------
/**
 * @brief Checks if a button is pressed.
 * @details Calls KSD_GetUserButton() and bitwise ands it with
 * maskArray[ \p nr ].\n
 * If the result of above is not 0, it will return 1 (true).\n
 * Otherwise it will return 0 (false).
 * @param[in] nr Number of the button to be checked.
 * @retval 1 true; button number \p nr is pressed.
 * @retval 0 false; button number \p nr is not pressed.
 * @note KSD_GetUserButton() is a funciton that is part of Tapko's KAIstack.
 * @note KSD_GetUserButton() Checks all four user buttons.
 * @note This function was made by Tapko for an example program.
 */
unsigned char GetButton(unsigned char nr) 
{
  return (KSD_GetUserButton()  &  maskArray[nr]) != 0 ;
}

//------------------------------------------------------------------
/**
 * @brief Gets the object value of a communication object.
 * @details Creates a variable.\n
 * Calls GetObjectValue() with \p objectNr and the reference of the created
 * value as the parameters.\n
 * Then returns the created value.
 * @param[in] objectNr The object number linked to a communication object
 * @returns The object value of a communication object.
 * @note GetObjectValue() is a function that is part of Tapko's KAIstack.
 * @note This function only works for communication objects with:\n
 * size <= 1 byte.
 * @note This function was made by Tapko for an example program.
 */
unsigned char GetObjVal(unsigned char objectNr)
{
  unsigned char tempObjectValue;

  GetObjectValue(objectNr, &tempObjectValue);   // get object value by function 
  return(tempObjectValue);
}

//------------------------------------------------------------------
// Initialization of application
//------------------------------------------------------------------
/**
 * @brief Initializes the LEDs, buttons, communication objects.
 * @details Configures the @ref list "lists" by
 * @ref dptXCreateList "creating empty lists".
 * @param none
 * @note This function gets called by KAIstack at the start of any application.
 * @note This function was made by Tapko but is altered.
 */
void APP_Init(void)
{
  unsigned char objCntr;
  unsigned char tempObjectValue=0;

  T_TRACE ("Init application\n");
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

  KSD_InitUserLED();                   // Init the 8 LEDs on EVAL board
  KSD_InitUserButton();                // Init the 4 buttons on EVAL board

// initialization of the application variables
  for (objCntr = CO_RW0; objCntr <= CO_RW12; objCntr++)
  {
    SetObjectValue(objCntr, &tempObjectValue); // initialize the object value
    if (objCntr < CO_RW4)
    	SetLed(objCntr,  GetObjVal(objCntr));
  }
  dpt1list = dpt1CreateEmptyList();
  dpt7list = dpt7CreateEmptyList();
  dpt10list = dpt10CreateEmptyList();
  dpt12list = dpt12CreateEmptyList();
  dpt215list = dpt215CreateEmptyList();
  dpt212list = dpt212CreateEmptyList();
  dpt19list = dpt19CreateEmptyList();
  dpt16list = dpt16CreateEmptyList();


#if 0
  KSD_InitUserLED();                   // Init the 8 LEDs on EVAL board
  KSD_InitUserButton();                // Init the 4 buttons on EVAL board
#endif
}


//------------------------------------------------------------------
// Main program of application (cyclic called) Time
//------------------------------------------------------------------
/**
 * @brief This is the heart of the application.
 * @details This function gets cyclicly called by KAIstack.\n
 * This function checks flags and variables to decide
 * what functions should be called.
 * @param none
 * @note This function gets cyclicly called by KAIstack.
 * @note This function was made by Tapko but is altered.
 */
void APP_Main(void)
{
	static unsigned char simulationActive = 0;
	static int16_t currTime = 0;
	static unsigned char passed2Weeks = 0;
	static unsigned char nextList = 0;
	const int16_t prevTime = currTime;

	currTime = RTC_GetTime();
	if (currTime != prevTime) {
		static unsigned char LED4 = 0;

		LED4 ^= 1;
		// 3 = LED4, because 0..3 is LED1..LED4
		SetLed(3, LED4);
		if (passed2Weeks && !simulationActive) {
			removeOldData(currTime);
		}
	}
	// RTC afhandeling
	if (RTC_GetFlagStatus(RTC_FLAG_ALR)) {
		static unsigned char weekIndicator = 0;

		passed2Weeks = 1;
		removeLastTime(prevTime); // Max Value
		RTC_SetTime(0);
		// Wait until SECF is set
		while (!(RTC->CRL & 0x01));
		// Clear the Alarm Flag
		RTC->CRL &= ~0x02;

		clearLocks(simulationActive);
		if (simulationActive) {
			//set nextList
			nextList = calcNextList();
		}
		weekIndicator ^= 1;
		// 0 = LED 1
		SetLed(0, weekIndicator);
	}

	simulationActive = CheckForUpdates(simulationActive, currTime, passed2Weeks);
	if (simulationActive) {
		nextList = simulatePresence(nextList, currTime);
	}
}

//------------------------------------------------------------------
#if SC_APPLICATION_TYPE == SC_APPL_CALL_EVENT
/**
 * @brief Handles incoming events.
 * @details Calls APP_Init() if \p event is SC_EVENT_INIT.\n
 * Calls APP_Main() if \p event is SC_EVENT_CYCLE.\n
 * Calls SC_SendEventAppl() with SC_TASK_APP1 and SC_EVENT_CYCLE as parameters.
 * @param[in] event The event to be handled.
 * @note SC_SendEventAppl() is a function that is part of Tapko's KAIstack.
 * @note This function is part of Tapko's KAIstack.
 */
void APP_EventHandler(SC_tEventMask event)
{
  if ((event & SC_EVENT_INIT) != 0)
    APP_Init();
  if ((event & SC_EVENT_CYCLE) != 0)
    APP_Main();
  SC_SendEventAppl(SC_TASK_APP1, SC_EVENT_CYCLE);
}
#endif

//------------------------------------------------------------------
// Save program of application 
//------------------------------------------------------------------
/**
 * @brief This function gets called when there is a significant voltage drop
 * of the KNX bus voltage.
 * @details This function is not used since it can only be used with the full
 * license for KAIstack.
 * @param none
 * @note This function is part of Tapko's KAIstack.
 */
void APP_Save(void)
{
}

//------------------------------------------------------------------
// NOTE: in APPHW... the group objects and Parameter may not be valid
//------------------------------------------------------------------
/**
 * @brief This function is only available with the full license for KAIstack.
 * @details This function is not used since it can only be used with the full
 * license for KAIstack.
 * @param none
 * @note This function is part of Tapko's KAIstack.
 */
void APPHW_Init(void)
{
}

//------------------------------------------------------------------
/**
 * @brief This function is only available with the full license for KAIstack.
 * @details This function is not used since it can only be used with the full
 * license for KAIstack.
 * @param none
 * @note This function is part of Tapko's KAIstack.
 */
void APPHW_Cycle(void)
{
}

#if SC_APPLICATION_TYPE == SC_APPL_CALL_EVENT

// Event handler for hardware part of the application
/**
 * @brief This function is only available with the full license for KAIstack.
 * @details This function is not used since it can only be used with the full
 * license for KAIstack.
 * @param event
 * @note This function is part of Tapko's KAIstack.
 */
void APPHW_EventHandler(SC_tEventMask event)
{
  if ((event & SC_EVENT_INIT) != 0)
    APPHW_Init();                      // Initialization
  if ((event & ~SC_EVENT_INIT) != 0)
    APPHW_Cycle();                     // cycle
}
#endif

//------------------------------------------------------------------
/**
 * @brief Checks for updates and performs related actions.
 * @details Checks if a button was pressed.\n
 * If a button was pressed makes sure the right follow up actions will be handled.\n
 * Checks if any of the update flags of the communication objects is set.\n
 * If an update flag is set and the simulation is inactive,
 * the message will be read.\n
 * If the simulation is active however, the message will be discarded.\n
 * (Unless the message is sent to the communication object which can activate and
 * deactivate the simulation.)
 * @param[in] activeSimulation Flag that shows if the simulation is active.
 * @param[in] rtc_time Current time in RTC time format.
 * @param[in] twoWeeksFlag Flag that shows if two weeks are passed.
 * @retval 1 true; If the simulation is active.
 * @retval 0 false; If the simulation is inactive.
 */
unsigned char CheckForUpdates(const unsigned char activeSimulation, const int16_t rtc_time, const unsigned char twoWeeksFlag) {
	unsigned char objCntr;
	unsigned char tempObjectValue;
	unsigned char oldKey[4];
	static unsigned char presentKey[4];

	if (activeSimulation) {
		oldKey[0] = presentKey[0];
		presentKey[0] = ((GPIO_KEY_1_Port->IDR) & GPIO_KEY_1_Pin);
		// GPIO_KEY_1_Port = GPIOB
		// GPIO_KEY_1_Pin = GPIO_Pin_2 = ((uint16_t)0x0004)
		// GPIO_KEY_2_Port = GPIOC
		// GPIO_KEY_2_Pin = GPIO_Pin_4 = ((uint16_t)0x0010)
		// GPIO_KEY_3_Port = GPIOC
		// GPIO_KEY_3_Pin = GPIO_Pin_3 = ((uint16_t)0x0008)
		// GPIO_KEY_4_Port = GPIOC
		// GPIO_KEY_4_Pin = GPIO_Pin_6 = ((uint16_t)0x0040)
		if ((0 != presentKey [0] && 0 == oldKey[0]) || CheckUpdateFlag(CO_RW0)) {
			return 0;
			// TO DO: What to do with all these old values?
			// Delete everything then lock and reset passed2weeks?
		}

		// -- Temporary should be in the next for loop without setting LED
		for (objCntr = CO_RW1; objCntr <= CO_RW2; objCntr++) {
			if (CheckUpdateFlag(objCntr)) {
				SetLed(objCntr, GetObjVal(objCntr));
			}
		}
		for (objCntr = CO_RW3; objCntr <= CO_RW12; objCntr++) {
			CheckUpdateFlag(objCntr);
			// Might need to call GetObjVal
		}

		return activeSimulation;
	}

	// The following code will only be processed if activeSimulation is false
	for (int i = 0; i < 4; i++) {
		oldKey[i] = presentKey[i];
		presentKey[i] = GetButton(i);
	}

	if ((0 != presentKey[0] && 0 == oldKey[0]) || CheckUpdateFlag(CO_RW0)) {
		startSimulation(rtc_time, twoWeeksFlag);
		return 1;
	}

	for (objCntr = CO_RW1; objCntr <= CO_RW2; objCntr++) {
		if (CheckUpdateFlag(objCntr)) {
			SetLed(objCntr, GetObjVal(objCntr));
			struct dpt1 d1 = {GetObjVal(objCntr), objCntr, rtc_time};
			dpt1PushList(dpt1list, d1);
			dpt1Lock &= 0x01;
		}
		if (0 != presentKey[objCntr] && 0 == oldKey[objCntr]) {
			GetObjectValue(objCntr, &tempObjectValue);
			tempObjectValue ^= 1;
			SetObjectValue(objCntr, &tempObjectValue);
			SetTransmitRequest(objCntr);
			SetLed(objCntr, tempObjectValue);
			struct dpt1 d1 = {GetObjVal(objCntr), objCntr, rtc_time};
			dpt1PushList(dpt1list, d1);
			dpt1Lock &= 0x01;
		}
	}

	if (0 != presentKey[3] && 0 == oldKey[3]) {
		// TO DO: Get KNX time
		int16_t timeDifference = 0;
		/*
		 * unsigned char* timeDiffBytes; // unsigned char timeDiffBytes[3]
		 * AL_TransmitObject([number of communication object], true, false);
		 * // ^ Read request because second parameter is true ^
		 * GetObjectValue([number of communication object], timeDiffBytes);
		 * timeDifference = timeDiffBytes[0] << 8 + timeDiffBytes[1];
		 */
		transmitAllToUSB(timeDifference);
	}

	for (objCntr = CO_RW3; objCntr <= CO_RW12; objCntr++) {
		if (CheckUpdateFlag(objCntr)) {
			struct dpt1 d1 = {GetObjVal(objCntr), objCntr, rtc_time};
			dpt1PushList(dpt1list, d1);
			dpt1Lock &= 0x01;
		}
	}

	return activeSimulation;
}
