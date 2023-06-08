#include "MySimulator.h"
#include "MyRealTimeClock.h"

#include "project.h"
#include "eib_stk.h"
#include "app.h"
#include EIB_DEVICE_MODEL_APP_H_FILE

extern dpt1_list* dpt1list;
extern dpt7_list* dpt7list;
extern dpt10_list* dpt10list;
extern dpt12_list* dpt12list;
extern dpt215_list* dpt215list;
extern dpt212_list* dpt212list;
extern dpt19_list* dpt19list;
extern dpt16_list* dpt16list;

///@cond
static void sendDPT1();
static void sendDPT7();
static void sendDPT10();
static void sendDPT12();
static void sendDPT215();
static void sendDPT212();
static void sendDPT19();
static void sendDPT16();
///@endcond

/**
 * @defgroup dptXLock Lock
 * @brief This variable is used to enable or disable certain actions.
 * @details During a simulation it makes sure that @ref dptX_list can
 * or can not be selected as next list.\n
 * When the node with the highest time has been sent, this variable will be set (1).\n
 * It will be reset (0) when the alarm flag of the rtc is set.\n\n
 * When the simulation is not active it makes sure that not too much nodes will be removed by
 * removeOldData().
 * @{
 */
/**
 * @name dptXLock
 * @brief This variable is used to enable or disable certain actions.
 * @{
 */
unsigned char dpt1Lock = 0, dpt7Lock = 0, dpt10Lock = 0,
		dpt12Lock = 0, dpt215Lock = 0, dpt212Lock = 0, dpt19Lock = 0,
		dpt16Lock = 0;
///@}
///@}

/**
 * @brief Calls configureLocks() to configure the locks.
 * @details If two weeks have passed, it configures the locks according to \p rtc_time.
 * Otherwise it configures the locks with 0 as parameter for configureLocks().
 * @param[in] rtc_time The current time in RTC time format.
 * @param[in] twoWeeksFlag Flag, should be true if two weeks have been passed else false
 */
void startSimulation(const int16_t rtc_time,
		const unsigned char twoWeeksFlag)
{
	if (twoWeeksFlag) {
		configureLocks(rtc_time);
	}
	else {
		configureLocks(0);
	}
}

/**
 * @brief Repeats KNX messages on the same time as they were received.
 * @details Checks if the @ref time in the first @ref dptX_node "node"
 * of the @ref list "list" corresponding to ::dptListNumber is lower than
 * \p rtc_time.\n\n
 * If this is the case, it will call @ref sendDPTX "sendDPTX()".\n
 * Then it will call calcNextList() to search for the next KNX message to be
 * repeated, and return the result.\n\n
 * Otherwise it will return the same value as \p nextList.
 * @param[in] nextList The ::dptListNumber of the @ref list "list"
 * that has to be repeated first.
 * @param[in] rtc_time The current time in RTC time format.
 * @retval listDPT1 If the data of @ref dpt1list should be repeated next.
 * @retval listDPT7 If the data of @ref dpt7list should be repeated next.
 * @retval listDPT10 If the data of @ref dpt10list should be repeated next.
 * @retval listDPT12 If the data of @ref dpt12list should be repeated next.
 * @retval listDPT215 If the data of @ref dpt215list should be repeated next.
 * @retval listDPT212 If the data of @ref dpt212list should be repeated next.
 * @retval listDPT19 If the data of @ref dpt19list should be repeated next.
 * @retval listDPT16 If the data of @ref dpt16list should be repeated next.
 * @retval 0 If all @ref list "lists" are empty or if all @ref list "lists" are locked.
 */
unsigned char simulatePresence(const unsigned char nextList,
		const int16_t rtc_time)
{
	switch (nextList) {
	case 0: {
		// All lists are locked
		return 0;
		break;
	}
	case listDPT1: {
		struct dpt1 d1 = dpt1FirstData(dpt1list);
		if (rtc_time >= d1.time) {
			sendDPT1(d1);
		}
		else {
			return listDPT1; // could also be nextList, but this is a constant
		}
		break;
	}
	case listDPT7: {
		struct dpt7 d7 = dpt7FirstData(dpt7list);
		if (rtc_time >= d7.time) {
			sendDPT7(d7);
		}
		else {
			return listDPT7;
		}
		break;
	}
	case listDPT10: {
		struct dpt10 d10 = dpt10FirstData(dpt10list);
		if (rtc_time >= d10.time) {
			sendDPT10(d10);
		}
		else {
			return listDPT10;
		}
		break;
	}
	case listDPT12: {
		struct dpt12 d12 = dpt12FirstData(dpt12list);
		if (rtc_time >= d12.time) {
			sendDPT12(d12);
		}
		else {
			return listDPT12;
		}
		break;
	}
	case listDPT215: {
		struct dpt215 d215 = dpt215FirstData(dpt215list);
		if (rtc_time >= d215.time) {
			sendDPT215(d215);
		}
		else {
			return listDPT215;
		}
		break;
	}
	case listDPT212: {
		struct dpt212 d212 = dpt212FirstData(dpt212list);
		if (rtc_time >= d212.time) {
			sendDPT212(d212);
		}
		else {
			return listDPT212;
		}
		break;
	}
	case listDPT19: {
		struct dpt19 d19 = dpt19FirstData(dpt19list);
		if (rtc_time >= d19.time) {
			sendDPT19(d19);
		}
		else {
			return listDPT19;
		}
		break;
	}
	case listDPT16: {
		struct dpt16 d16 = dpt16FirstData(dpt16list);
		if (rtc_time >= d16.time) {
			sendDPT16(d16);
		}
		else {
			return listDPT16;
		}
		break;
	}
	default: {
		// Error case, returning 0
		// Turn light on?
		return 0;
		break;
	}
	}
	return calcNextList();
}

/**
 * @brief Configures the @ref dptXLock "locks".
 * @details Checks per @ref list "list" whether or not the @ref time in the
 * first @ref dptX_node "node" is higher or lower than \p time.\n
 * If the time in the first @ref dptX_node "node" is lower
 * @ref dptXLock "lock" will be set to 1, else @ref dptXLock "lock" will be set to 0.
 * @param[in] rtc_time The current RTC time
 * @note If this function is called while the RTC alarm has not been set before,
 * \p time should be set to 0.
 */
void configureLocks(const int16_t rtc_time)
{
	// Should be locked if list is empty or if the first data should be
	// repeated in the next 2 week interval
	// CheckEmpty() does not have to be called since:
	// FirstData().time = 0 for an empty list and 0 < time will be true.
	// Even though CheckEmpty() is faster so if the list is empty this
	// it would be beneficial. However the lists are not expected to be
	// empty so in regular use it would unnecessary (and more processing).
	if (dpt1FirstData(dpt1list).time < rtc_time) {
		dpt1Lock = 1;
	}
	else {
		dpt1Lock = 0;
	}
	if (dpt7FirstData(dpt7list).time < rtc_time) {
		dpt7Lock = 1;
	}
	else {
		dpt7Lock = 0;
	}
	if (dpt10FirstData(dpt10list).time < rtc_time) {
		dpt10Lock = 1;
	}
	else {
		dpt10Lock = 0;
	}
	if (dpt12FirstData(dpt12list).time < rtc_time) {
		dpt12Lock = 1;
	}
	else {
		dpt12Lock = 0;
	}
	if (dpt215FirstData(dpt215list).time < rtc_time) {
		dpt215Lock = 1;
	}
	else {
		dpt215Lock = 0;
	}
	if (dpt212FirstData(dpt212list).time < rtc_time) {
		dpt212Lock = 1;
	}
	else {
		dpt215Lock = 1;
	}
	if (dpt19FirstData(dpt19list).time < rtc_time) {
		dpt19Lock = 1;
	}
	else {
		dpt19Lock = 0;
	}
	if (dpt16FirstData(dpt16list).time < rtc_time) {
		dpt16Lock = 1;
	}
	else {
		dpt16Lock = 0;
	}
}

/**
 * @brief Sets the @ref dptXLock "locks" to their start value.
 * @details Sets the @ref dptXLock "locks" according to \p simulating.\n
 * If \p simulating is true all @ref dptXLock "locks" will be set to 0, unlocking
 * the lists for calcNextList().\n
 * If \p simulating is false all @ref dptXLock "locks" will be set to 2, locking
 * the lists for removeOldData() and removeLastTime().
 * @param[in] simulating Should be true if a simulation is active,
 * should be false if no simulation is active.
 */
void clearLocks(const unsigned char simulating)
{
	if (simulating) {
		// Clear the Locks
		dpt1Lock = 0;
		dpt7Lock = 0;
		dpt10Lock = 0;
		dpt12Lock = 0;
		dpt215Lock = 0;
		dpt212Lock = 0;
		dpt19Lock = 0;
		dpt16Lock = 0;
	}
	else {
		// Clear all bits and set bit 1.
		dpt1Lock = 2;
		dpt7Lock = 2;
		dpt10Lock = 2;
		dpt12Lock = 2;
		dpt215Lock = 2;
		dpt212Lock = 2;
		dpt19Lock = 2;
		dpt16Lock = 2;
	}
}

/**
 * @brief Checks what data should be repeated first.
 * @details Checks per @ref list "list" if the list is @ref dptXLock "locked",
 * then checks if the @ref list "list" is not empty, then checks if the
 * @ref time of the first @ref dptX_node "node" is smaller than a variable.\n
 * If this is the case the variable will become that @ref time, and the output
 * variable will be updated to the corresponding ::dptListNumber.\n
 * Then it checks the same for the next @ref list "lists".
 * @param none
 * @retval listDPT1 If the data of @ref dpt1list should be repeated next.
 * @retval listDPT7 If the data of @ref dpt7list should be repeated next.
 * @retval listDPT10 If the data of @ref dpt10list should be repeated next.
 * @retval listDPT12 If the data of @ref dpt12list should be repeated next.
 * @retval listDPT215 If the data of @ref dpt215list should be repeated next.
 * @retval listDPT212 If the data of @ref dpt212list should be repeated next.
 * @retval listDPT19 If the data of @ref dpt19list should be repeated next.
 * @retval listDPT16 If the data of @ref dpt16list should be repeated next.
 * @retval 0 If all @ref list "lists" are empty or if all @ref list "lists" are locked.
 */
unsigned char calcNextList(void)
{
	unsigned char nextList = 0;
	short nextTime = 65535;
	// Check for lock first because it is more likely to fail and it is faster.
	if (!dpt1Lock && !dpt1CheckEmpty(dpt1list)) {
		nextTime = dpt1FirstData(dpt1list).time;
		nextList = listDPT1;
	}
	if (!dpt7Lock && !dpt7CheckEmpty(dpt7list)
			&& nextTime > dpt7FirstData(dpt7list).time) {
		nextTime = dpt7FirstData(dpt7list).time;
		nextList = listDPT7;
	}
	if (!dpt10Lock && !dpt10CheckEmpty(dpt10list)
			&& nextTime > dpt10FirstData(dpt10list).time) {
		nextTime = dpt10FirstData(dpt10list).time;
		nextList = listDPT10;
	}
	if (!dpt12Lock && !dpt12CheckEmpty(dpt12list)
			&& nextTime > dpt12FirstData(dpt12list).time) {
		nextTime = dpt12FirstData(dpt12list).time;
		nextList = listDPT12;
	}
	if (!dpt215Lock && !dpt215CheckEmpty(dpt215list)
			&& nextTime > dpt215FirstData(dpt215list).time) {
		nextTime = dpt215FirstData(dpt215list).time;
		nextList = listDPT215;
	}
	if (!dpt212Lock && !dpt212CheckEmpty(dpt212list)
			&& nextTime > dpt212FirstData(dpt212list).time) {
		nextTime = dpt212FirstData(dpt212list).time;
		nextList = listDPT212;
	}
	if (!dpt19Lock && !dpt19CheckEmpty(dpt19list)
			&& nextTime > dpt19FirstData(dpt19list).time) {
		nextTime = dpt19FirstData(dpt19list).time;
		nextList = listDPT19;
	}
	if (!dpt16Lock && !dpt16CheckEmpty(dpt16list)
			&& nextTime > dpt16FirstData(dpt16list).time) {
		nextTime = dpt16FirstData(dpt16list).time;
		nextList = listDPT16;
	}
	return nextList;
}

/**
 * @defgroup sendDPTX Send one dataStruct to KNX
 * @brief Sends one \p dataStruct to the KNX bus.
 * @details Sends the KNX message stored in the \p dataStruct.\n
 * Then it will call @ref dptXFirstToLast "FirstToLast()" to move the
 * @ref dptX_node "node" to the end of @ref list "list".
 * @param[in] dataStruct The @ref dataStruct "dataStruct" that will be sent.
 * @note This function is static and can only be called from this
 * @ref MySimulator.c "file".
 * @{
 */

/**
 * @name sendDPTX
 * @brief Sends one \p dataStruct to the KNX bus.
 * @details Sends the KNX message stored in the \p dataStruct.\n
 * Then it will call @ref dptXFirstToLast "FirstToLast()" to move the
 * @ref dptX_node "node" to the end of @ref list "list".
 * @param[in] dataStruct The @ref dataStruct "dataStruct" that will be sent.
 * @note These functions are static and can only be called from this
 * @ref MySimulator.c "file".
 * @{
 */
static void sendDPT1(struct dpt1 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, &dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt1FirstToLast(dpt1list);
	if (dataStruct.time > dpt1FirstData(dpt1list).time) {
		dpt1Lock = 1;
	}
}

static void sendDPT7(struct dpt7 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt7FirstToLast(dpt7list);
	if (dataStruct.time > dpt7FirstData(dpt7list).time) {
		dpt7Lock = 1;
	}
}

static void sendDPT10(struct dpt10 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt10FirstToLast(dpt10list);
	if (dataStruct.time > dpt10FirstData(dpt10list).time) {
		dpt10Lock = 1;
	}
}

static void sendDPT12(struct dpt12 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt12FirstToLast(dpt12list);
	if (dataStruct.time > dpt12FirstData(dpt12list).time) {
		dpt12Lock = 1;
	}
}

static void sendDPT215(struct dpt215 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt215FirstToLast(dpt215list);
	if (dataStruct.time > dpt215FirstData(dpt215list).time) {
		dpt215Lock = 1;
	}
}

static void sendDPT212(struct dpt212 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt212FirstToLast(dpt212list);
	if (dataStruct.time > dpt212FirstData(dpt212list).time) {
		dpt212Lock = 1;
	}
}

static void sendDPT19(struct dpt19 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt19FirstToLast(dpt19list);
	if (dataStruct.time > dpt19FirstData(dpt19list).time) {
		dpt19Lock = 1;
	}
}

static void sendDPT16(struct dpt16 dataStruct)
{
	SetObjectValue(dataStruct.grpAd, dataStruct.dat);
	SetTransmitRequest(dataStruct.grpAd);
	dpt16FirstToLast(dpt16list);
	if (dataStruct.time > dpt16FirstData(dpt16list).time) {
		dpt16Lock = 1;
	}
}
///@}
///@}

/**
 * @brief Removes the @ref dptX_node "nodes" with a @ref time smaller than \p time.
 * @details If the @ref list "list" is not locked and the @ref time of the first
 * @ref dptX_node "node" is smaller than \p time the first @ref dptX_node "nodes"
 * will be removed until the @ref time is no longer smaller than \p time.
 * @param[in] time
 * @warning Since only nodes with a time smaller than \p time are removed,
 * the nodes with the highest possible time will not be removed by this
 * function if \p time is the actual time.
 */
void removeOldData(const short time)
{
	// Check if list is empty in case last data was removed
	while (!dpt1Lock && !dpt1CheckEmpty(dpt1list)
			&& dpt1FirstData(dpt1list).time < time) {
		struct dpt1 d1 = dpt1PopFirst(dpt1list);
		// if new week started don't remove all data
		if (d1.time > dpt1FirstData(dpt1list).time) {
			dpt1Lock = 1;
			break;
		}
	}
	// Check Lock first because it is most likely to fail and it does not cost much processing
	// C99 Standard: The && operator guarantees left-to-right evaluation
	// C99 Standard: As soon as one part fails, the others won't be processed
	while (!dpt7Lock && !dpt7CheckEmpty(dpt7list)
			&& dpt7FirstData(dpt7list).time < time) {
		struct dpt7 d7 = dpt7PopFirst(dpt7list);
		if (d7.time > dpt7FirstData(dpt7list).time) {
			dpt7Lock = 1;
			break;
		}
	}
	while (!dpt10Lock && !dpt10CheckEmpty(dpt10list)
			&& dpt10FirstData(dpt10list).time < time) {
		struct dpt10 d10 = dpt10PopFirst(dpt10list);
		if (d10.time > dpt10FirstData(dpt10list).time) {
			dpt10Lock = 1;
			break;
		}
	}
	while (!dpt12Lock && !dpt12CheckEmpty(dpt12list)
			&& dpt12FirstData(dpt12list).time < time) {
		struct dpt12 d12 = dpt12PopFirst(dpt12list);
		if (d12.time > dpt12FirstData(dpt12list).time) {
			dpt12Lock = 1;
			break;
		}
	}
	while (!dpt215Lock && !dpt215CheckEmpty(dpt215list)
			&& dpt215FirstData(dpt215list).time < time) {
		struct dpt215 d215 = dpt215PopFirst(dpt215list);
		if (d215.time > dpt215FirstData(dpt215list).time) {
			dpt215Lock = 1;
			break;
		}
	}
	while (!dpt212Lock && !dpt212CheckEmpty(dpt212list)
			&& dpt212FirstData(dpt212list).time < time) {
		struct dpt212 d212 = dpt212PopFirst(dpt212list);
		if (d212.time > dpt212FirstData(dpt212list).time) {
			dpt212Lock = 1;
			break;
		}
	}
	while (!dpt19Lock && !dpt19CheckEmpty(dpt19list)
			&& dpt19FirstData(dpt19list).time < time) {
		struct dpt19 d19 = dpt19PopFirst(dpt19list);
		if (d19.time > dpt19FirstData(dpt19list).time) {
			dpt19Lock = 1;
			break;
		}
	}
	while (!dpt16Lock && !dpt16CheckEmpty(dpt16list)
			&& dpt16FirstData(dpt16list).time < time) {
		struct dpt16 d16 = dpt16PopFirst(dpt16list);
		if (d16.time > dpt16FirstData(dpt16list).time) {
			dpt16Lock = 1;
			break;
		}
	}
}

/**
 * @brief Removes the @ref dptX_node "nodes" with the same @ref time as \p maxValue.
 * @details If the @ref list "list" is not locked and the @ref time of the first
 * @ref dptX_node "node" is the same as \p maxValue the first @ref dptX_node "nodes"
 * will be removed until the @ref time is no longer the same as \p maxValue.
 * @param[in] maxValue
 * @note This function only exists to make sure the
 * messages with the highest time also get removed.\n
 * Since the function removeOldData() only removes data
 * with a time smaller than the given time.
 */
void removeLastTime(const short maxValue)
{
	// CheckEmpty() does not have to be called since FirstData().time will not
	// be equal to maxValue if the list is empty.
	while (!dpt1Lock && dpt1FirstData(dpt1list).time == maxValue) {
		dpt1PopFirst(dpt1list);
	}
	while (!dpt7Lock && dpt7FirstData(dpt7list).time == maxValue) {
		dpt7PopFirst(dpt7list);
	}
	while (!dpt10Lock && dpt10FirstData(dpt10list).time == maxValue) {
		dpt10PopFirst(dpt10list);
	}
	while (!dpt12Lock && dpt12FirstData(dpt12list).time == maxValue) {
		dpt12PopFirst(dpt12list);
	}
	while (!dpt215Lock && dpt215FirstData(dpt215list).time == maxValue) {
		dpt215PopFirst(dpt215list);
	}
	while (!dpt212Lock && dpt212FirstData(dpt212list).time == maxValue) {
		dpt212PopFirst(dpt212list);
	}
	while (!dpt19Lock && dpt19FirstData(dpt19list).time == maxValue) {
		dpt19PopFirst(dpt19list);
	}
	while (!dpt16Lock && dpt16FirstData(dpt16list).time == maxValue) {
		dpt16PopFirst(dpt16list);
	}
}
