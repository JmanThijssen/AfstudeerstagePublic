//------------------------------------------------------------------
// $Workfile: app_data.c $   
// $Archive: /eib_stk/appl_example/empty/src/app_data.c $     

// $Author: Zivkovic_z $         
// 
// Copyright Tapko Technologies GmbH
// 
// $Date: 2016-10-04 10:30:50 +0200 (Di, 04 Okt 2016) $
// $Revision: 3125 $         
//------------------------------------------------------------------

// !!
// !!  Individual address to use in ETS5
// !!

#define EVALKITSTKNX_05 0x1505
#define EVALKITSTKNX_06 0x1506
#define EVALKITSTKNX_07 0x1507
#define EVALKITSTKNX_08 0x1508
#define EVALKITSTKNX_09 0x1509


#define KNX_DEF_INDIVIDUAL_ADDR EIB_ADDR(EVALKITSTKNX_06)

#define KNX_CURRENT_ADDR_TAB_LEN 13
#define KNX_CURRENT_ASSOC_TAB_LEN 13

//------------------------------------------------------------------
// this block is used for generation of documentation
//------------------------------------------------------------------
#ifdef KAI_GENERATE_DOC
/**
This makro is used to define the addresses, association, communication objects and enums for the communication objects.
The order of the makros defines the order of the group communication objects.
\n There are restictions on the associated addresses. 
There is a 1 to 1 assignmet for group addresses to the group communication objects.
The group addresses has to be in ascending order.

@param index  name for the numeration of the group communication object
@param groupAddr group address for this communication object
@param dataPtr pointer to the data of the communication object
@param objType type of the communication object
@param DPT data point type (DPT) of the communication object
@param flags configuration flags of the communication object
@param priority priority of the communication object0

@code 
DEFINE_COMM_OBJ(CO_in0,  ETS_GROUP3(2,0,0), RAM_PTR(in0), CO_TypeUint1, 1, CO_WU, CO_PRIO_L),
@endcode 
*/
#define DEFINE_COMM_OBJ(index,  groupAddr, dataPtr, objType, DPT, flags, priority),
#endif

START_TAB()
DEFINE_COMM_OBJ(CO_RW0,		ETS_GROUP3(2,0,0),		RAM_PTR(in0),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW1,		ETS_GROUP3(2,0,1),		RAM_PTR(in1),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW2,		ETS_GROUP3(2,0,2),		RAM_PTR(in2),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW3,		ETS_GROUP3(2,0,3),		RAM_PTR(in3),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW4,		ETS_GROUP3(2,0,4),		RAM_PTR(in4),	CO_TypeUint4, 4, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW5,		ETS_GROUP3(2,0,5),		RAM_PTR(in5),	CO_TypeUint4, 4, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW6,		ETS_GROUP3(2,0,6),		RAM_PTR(in6),	CO_TypeByte1, 4, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW7,		ETS_GROUP3(2,0,7),		RAM_PTR(in7),	CO_TypeUint1, 6, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW8,		ETS_GROUP3(9,0,0),		RAM_PTR(in8),	CO_TypeUint2, 2, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW9,		ETS_GROUP3(2,0,8),		RAM_PTR(in9),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW10,	ETS_GROUP3(2,0,9),		RAM_PTR(in10),	CO_TypeByte1, 6, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW11,	ETS_GROUP3(2,0,10),		RAM_PTR(in11),	CO_TypeByte1, 6, CO_RTWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_RW12,	ETS_GROUP3(2,0,11),		RAM_PTR(in12),	CO_TypeUint1, 1, CO_RTWU, CO_PRIO_L)

END_TAB()


/*
1 bit 
1 bit
1 bit
1 bit
1 bit
4 bit
4 bit
1 byte
1 bit
2 bit
1 bit
1 byte
1 byte
1 bit
 */

/*
 *
 */

