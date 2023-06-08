//{{TAPKO_EXPORT_MIC
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
// $HeadURL: https://tapko-app:1443/svn/KAIstack/branches/KAIstack_branches/KAI_securityBranch/appl_example/inOut4/src/project.h $
//
// Project:           EIB-Communication-Stack
//
// $Author: Zivkovic_z $
//
// $Date: 2016-10-04 10:40:42 +0200 (Di, 04 Okt 2016) $
// $Revision: 3126 $
//------------------------------------------------------------------
/// @addtogroup KAI_project_hRef
/// @{

//}}TAPKO_EXPORT_MIC
#include "constant.h"

/**
Indicates that project settings are included
*/
#define PROJECT_SETTINGS

// automatic detection of the win32 project
#ifdef WIN32
#define DEBUG_WIN32          // debug version for PC without EEPROM
#endif

//------------------------------------------------------------------
//------------------------------------------------------------------
//{{TAPKO_EXPORT_MIC
#define DEBUG   1
#define KNX_DEMO 1
//#define STM32_CUBE_LL 1
//#define USE_FULL_LL_DRIVER 1

//#define HSE_VALUE 16000000

#define WDG_INIT()    //WDG_HAL_Init()
#define WDG_RESET()   //LL_IWDG_ReloadCounter(IWDG)
#define WDG_START()   //{ LL_IWDG_ReloadCounter(IWDG); LL_IWDG_Enable(IWDG); }
#define WDG_STOP()   /* unstoppable */

//------------------------------------------------------------------
/**
@anchor EIB_DEVICE_MODEL
This constant defines the KNX device model
possible definitions are (not complete):
- EIB_DEVICE_MODEL_0705
- EIB_DEVICE_MODEL_5705
@see KAI_DevMod_General, KAI_DevMod, KAI_devModels
*/
#define EIB_DEVICE_MODEL   EIB_DEVICE_MODEL_07B0

//------------------------------------------------------------------
/**
@anchor AST_FORMAT
This constant defines the format of the association table for system B
@see AST_FORMAT_constants
*/
#define AST_FORMAT AST_FORMAT_SMALL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// enables the EIB-easy controller mode
//#define EIB_EASY_CONTROLLER_MODE
//#define EIB_EASY_PARAMETER_SIZE 1

//------------------------------------------------------------------
// this section defines the board specific settings
// e.g. Microcontroller, KNX-IO ports, frequency, Compiler
//------------------------------------------------------------------

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// KNX_TARGET  - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/**
defining the target platform
this includes:
- microcontroller family
- compiler, including version
- type of communication interface to KNX (KAIlink)
possible targets are (not complete):
- communication interface: TPUART:
  - MSP430_IAR4_TF
  - MSP430_IAR5_TF
  - M16C_IAR_TF
  - STM8_IAR1_TF
  - AVR_IAR5_TF
- communication interface: KAIlink BIT, FZE 1066
  - MSP430_IAR4_DF
  - MSP430_IAR5_DF
@see Targets
*/
#define KNX_TARGET  STM32_GCC_DF
//#define KNX_TARGET  STM32_GCC_DE

//------------------------------------------------------------------
// DERIVATE  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/**
Defines the derivate of the microcontroller family.
This variable is used to adapt the register access and the linking
examples for possible definitions (not complete)
- MSP430F149
- MSP430F2370
- MSP430F249
- MSP430F449
- MSP430F5528
- STM8L152C6
@see Targets
*/
#define DERIVATE           STM32F103xB


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// defining type of the build
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define MAKE_USE_LIB        1
//#define MAKE_BUILD_LIB      1

//#define LIB_TYPE            SYSTEM_LIB TARGET_LIB

//------------------------------------------------------------------
/**
If the constant KAISTACK_EVAL_BOARD_H is defined,
the board definition files for the KAIstack eval boards are included.
If this constant is not defined,
the application specific board definition file (e.g. KAI_board.h) has to be included.
*/
#define KAISTACK_EVAL_BOARD_H TAPKO_DEFAULT_BOARD

//------------------------------------------------------------------
// this section defines required for the make process
// e.g. build type stack, additional defines
//------------------------------------------------------------------

// stack size
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//#define STACK_SIZE         200

//}}TAPKO_EXPORT_MIC
//------------------------------------------------------------------
//------------------------------------------------------------------

//------------------------------------------------------------------
// this section defines the KAIstack specific settings
//------------------------------------------------------------------

//------------------------------------------------------------------
/**
Enables additional check routines. E.g. Consistence check of pointer, sorting of tables.
An error will lead to an error in the corresponding state machine.
*/
#define MEMORY_CHECK

/// @}
