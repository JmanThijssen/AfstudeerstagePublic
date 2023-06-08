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
// $HeadURL: https://tapko-app:1443/svn/KAIstack/branches/KAIstack_branches/KAI_securityBranch/appl_example/inOut4/src/app_data.c $
//
// Project:           EIB-Communication-Stack
//
// $Author: Zivkovic_z $
//
// $Date: 2016-10-04 10:30:50 +0200 (Di, 04 Okt 2016) $
// $Revision: 3125 $
//------------------------------------------------------------------
#include "project.h"
#include "eib_stk.h"
#include "app.h"
#include EIB_DEVICE_MODEL_APP_H_FILE

//------------------------------------------------------------------
// start of EEPROM data
#include "mem_eeprom.h"
#ifdef BCU_EEPROM_INIT
//------------------------------------------------------------------
// initialization of EEPROM-constants
//------------------------------------------------------------------

BCU_DEFINE_EEPROM_INIT = {
   SYS_EEPROM1
// ------------------------------------   address table
#define KAI_DEF_ADDR_TAB
#include "def_CommObj.h"
#include "cotab.h"
// ------------------------------------   association table
#define KAI_DEF_ASSOC_TAB
#include "def_CommObj.h"
#include "cotab.h"
// ------------------------------------   object table
#define KAI_DEF_CO_TAB
#include "def_CommObj.h"
#include "cotab.h"
// ------------------------------------   easy parameter
#ifdef EIB_EASY_PARAMETER_SIZE
   {0},
#endif
// ------------------------------------   parameter (APP_Parameter)
   {
     INT_CONST(2)                       // delay
   },

#ifdef APPLICATION_EEPROM
// ------------------------------------   applikation EEPROM (APP_Eeprom)
   {
     0
   },
#endif
// ------------------------------------   system data
   SYS_EEPROM2
    };                           

MEMSEG_EEPROM char DM_easyChannelInfo[8] = {0,0,0,0,0,0,0,0};
#endif

#ifdef BCU_EEPROM_NO_INIT
BCU_DEFINE_EEPROM_NO_INIT;
MEMSEG_EEPROM char DM_easyChannelInfo[8];
#endif


//------------------------------------------------------------------
// end of EEPROM data
#include "mem_default.h"
//------------------------------------------------------------------

#define KAI_DEF_CO_PTR
#include "def_CommObj.h"
#include "cotab.h"

//------------------------------------------------------------------
// start of dummy segment
#include "mem_dummy.h"
//------------------------------------------------------------------

//------------------------------------------------------------------
// Declaration of the ETS Parameter
//------------------------------------------------------------------
//PAR_<type>_<length>_<offset>_<name>
//ETS_PARAMETER (delayTime, UI_16_0);


//------------------------------------------------------------------
// end of dummy segments
#include "mem_default.h"
//------------------------------------------------------------------
#ifdef EIB_INTERFACE_OBJECTS
#define OBJECT_TYPE_KAI_DEMO       0xff01

#if 1
INTERFACE_OBJECT_START(Prop_KAIdemo, OBJECT_TYPE_KAI_DEMO)
  DEF_PROPERTY (200, propRW, IOC_ARRAY,             PDT_INT,   &PARAMETER.delayTime),
INTERFACE_OBJECT_END()
#else
INTERFACE_OBJECT_START(Prop_KAIdemo, OBJECT_TYPE_KAI_DEMO)
  DEF_PROPERTY_SEC (200, propRW, SAL_AP_3FF_3FF, IOC_DATA_ARRAY,             PDT_INT,   &PARAMETER.delayTime),
INTERFACE_OBJECT_END()
#endif

KAI_CONST_DATA BCU_ObjectTable MN_userObjects =
{
 (KAI_CONST_DATA BCU_ObjectDesc *) &Prop_KAIdemo,
  0
};
#endif // EIB_INTERFACE_OBJECTS
