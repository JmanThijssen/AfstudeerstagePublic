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
// $HeadURL: https://tapko-app:1443/svn/KAIstack/branches/KAIstack_branches/KAI_securityBranch/appl_example/inOut4/src/app.h $
//
// Project:           EIB-Communication-Stack
//
// $Author: Adler_K $
//
// $Date: 2016-10-18 16:57:42 +0200 (Di, 18 Okt 2016) $
// $Revision: 3136 $
//------------------------------------------------------------------
/// @addtogroup KAI_app_h app.h
/// @{

//------------------------------------------------------------------
//------------------------------------------------------------------
// application / HW IDs
//------------------------------------------------------------------
//------------------------------------------------------------------
/**
Defines the manufacturer ID for the application. 
The manufacturer ID is a 16 bit value.
The manufacturer ID is assigned by the KNX Association,
@see ETS manufacturer tool
*/
#define APP_MANUF_ID         KNX_MANUF_TAPKO

//------------------------------------------------------------------
/**
Defines the application ID of the application. 
The application ID is a 16 bit value. 
This is together with the manufacturer ID and version a unique ID for the application over all manufacturers.
The application ID is managed by each manufacturer itself.
@see ETS manufacturer tool, APP_MANUF_ID, APP_APPL_VERSION
*/
#if EIB_DEVICE_MODEL == EIB_DEVICE_MODEL_0705
  #define APP_APPL_ID          0xF026
#endif
#if EIB_DEVICE_MODEL == EIB_DEVICE_MODEL_07B0 
  #define APP_APPL_ID          0xF027
#endif
#if EIB_DEVICE_MODEL == EIB_DEVICE_MODEL_2705
  #define APP_APPL_ID          0xF028
#endif
#if EIB_DEVICE_MODEL == EIB_DEVICE_MODEL_27B0 
  #define APP_APPL_ID          0xF029
#endif

//------------------------------------------------------------------
/**
Defines the application version. The application version is a 8 bit value 
The application version is managed by each manufacturer itself 
@see ETS manufacturer tool, APP_MANUF_ID, APP_APPL_ID
*/
#define APP_APPL_VERSION     1

//------------------------------------------------------------------
/**
Defines the order number of the hardware. 
This constant is not evaluated by the system. 
It can be displayed with ETS. 
The order number is a 10 byte string 
@see ETS manufacturer tool,
*/
#define APP_ORDER_NR         1,2,3,4,5,6,7,8,9,0 

//------------------------------------------------------------------
/**
This constant defines the hardware type. 
This type has to be 6 bytes long. 
The usage and constraints are defined in the KNX specification. 
The usage of the hardware type is enabled by the device model or via KNX_HW_TYPE_ENABLE. 
The first byte of the hardware type is 00h and specifies the format of the other five octets.
@see KNX Specifiction 3/5/1 Resources PID_HARDWARE_TYPE
@see KNX Specifiction Volume 6.
*/
#define KNX_HW_TYPE          0x00,_LOBYTE(APP_MANUF_ID),0xff,0xff,0xff,0x01

//------------------------------------------------------------------
/**
*/
#define KNX_FIRMWARE_VER     KNX_VERSION(0,1,2)

//------------------------------------------------------------------
//------------------------------------------------------------------
// size of systemtables
//------------------------------------------------------------------
//------------------------------------------------------------------
/**
Size of the address table (excluding physical address) 
With this constant the amount of memory for the address table is reserved.
The maximum allowed size depends on the device model. 
*/
#define APP_addrTabSize      16       

//------------------------------------------------------------------
/**
Size of the association table  
With this constant the amount of memory for the association table is reserved. 
The maximum size depends on the device model. 
*/
#define APP_assocTabSize     16       

//------------------------------------------------------------------
/**
Number of group communication objects. 
The maximum size depends on the device model. 
*/
#define APP_objectTabSize    13

//------------------------------------------------------------------
//------------------------------------------------------------------
//configuration of timer
//------------------------------------------------------------------
//------------------------------------------------------------------

//------------------------------------------------------------------
/**
Specifies the number of timers, which are available. 
3 Timer are used by the system. By default the timer numbers 0 to 2 are used.
*/
#define TM_TIMER_NR          4         // number of timer (3 used by system)

#define UserTimer            3
// ....

//------------------------------------------------------------------
// definition of communication objects
//-----------------------------------------------------------------
enum CommObjects {
#define KAI_DEF_CO_ENUM
#include "def_CommObj.h"
#include "cotab.h"    // #include "coTAb.h"
};

//------------------------------------------------------------------
/**
definition des BCU-RAM
This structure contains the data of the group communication objects and RAM-Flags.
*/
//------------------------------------------------------------------
typedef struct {
  unsigned char ramFlags[APP_objectTabSize];              // RAM-flags
  unsigned char in0;                                      // Objektwerte
  unsigned char in1;
  unsigned char in2;
  unsigned char in3;
  unsigned char in4;
  unsigned char in5;
  unsigned char in6;
  unsigned char in7;
  unsigned char in8;
  unsigned char in9;
  unsigned char in10;
  unsigned char in11;
  unsigned char in12;
} APP_Ram;

//------------------------------------------------------------------
/** 
@brief definition of EEPROM-Parameter for ETS
The parameters are defined in the structure APP_Parameter in app.h.
The parameters are defined as a part of the structure DM_EEPROM, 
which contains the whole EEPROM data. 
At least one parameter has to be defined. 
This structure can contain other structures or arrays.  
The parameters are initialised in the file app_data.c.
*/
typedef struct
{
  unsigned short delayTime;  
} APP_Parameter;

//------------------------------------------------------------------
// definition of EEPROM-Parameter not in ETS
//-----------------------------------------------------------------
typedef struct
{
  unsigned short dummy;
} APP_Eeprom;
