#pragma once
#ifndef MYSTORAGE_H
/// Include guard even though \#pragma once
#define MYSTORAGE_H

/**
 * @defgroup DPT dptX
 * @brief This structure contains all important KNX data of one KNX message.
 * @details This structure contains the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time format).
 * @{
 */

/**
 * @defgroup dat data
 * @brief The raw data of a KNX message.
 * @details The raw data of a KNX message in big endian.
 */

/**
 * @defgroup grpAd group address
 * @brief The group address to which the KNX message was sent.
 * @details The group address can be deducted using following:
 * <pre>
 * [             MSB             ] [             LSB             ]
 * [7] [6] [5] [4] [3] [2] [1] [0] [7] [6] [5] [4] [3] [2] [1] [0]
 * [      Main       ] [  Middle ] [             Sub             ]
 * </pre>
 * @note This variable holds the value of the groupaddress,
 * it is however not the actual group address.
 */

/**
 * @defgroup time time
 * @brief The time at which the KNX message was received.
 * @details The time is in RTC time format, so it is not the actual time.
 */

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time format).
 * @details A structure holding information of KNX messages with
 * sizeof(@ref dat) <= 1 byte.
 */

// 1 byte
struct __attribute__ ((__packed__)) dpt1 {
	unsigned char dat;				///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  1 byte < sizeof(@ref dat) <= 2 bytes.
 */
// 2 bytes
struct __attribute__ ((__packed__)) dpt7 {
	unsigned char dat[2];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  2 bytes < sizeof(@ref dat) <= 3 bytes.
 */
// 3 bytes
struct __attribute__ ((__packed__)) dpt10 {
	unsigned char dat[3];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  3 bytes < sizeof(@ref dat) <= 4 bytes.
 */
// 4 bytes
struct __attribute__ ((__packed__)) dpt12 {
	unsigned char dat[4];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  4 bytes < sizeof(@ref dat) <= 5 bytes.
 */
// 5 bytes
struct __attribute__ ((__packed__)) dpt215 {
	unsigned char dat[5];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  5 bytes < sizeof(@ref dat) <= 6 bytes.
 */
// 6 bytes
struct __attribute__ ((__packed__)) dpt212 {
	unsigned char dat[6];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  6 bytes < sizeof(@ref dat) <= 8 bytes.
 */
// 8 bytes
struct __attribute__ ((__packed__)) dpt19 {
	unsigned char dat[8];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};

/**
 * @brief A structure holding the data of a KNX message, the group address
 * it was sent to and the time on which it was received (in RTC time foramat).
 *  @details A structure holding information of KNX messages with
 *  sizeof(@ref dat) = 14 bytes or KNX messages with varying size.
 */
// 14 bytes
struct __attribute__ ((__packed__)) dpt16 {
	unsigned char dat[14];			///< @ingroup dat
	unsigned short grpAd;			///< @ingroup grpAd
	short time;						///< @ingroup time
};
///@}

/**
 * @defgroup dptX_node
 * @brief Node of a @ref dptX_list.
 * @{
 */

/**
 * @defgroup dataStruct
 * @brief The data of a @ref dptX_node.
 * @details A struct containing all the data of a KNX message.
 */

/**
 * @defgroup next next pointer
 * @brief A pointer pointing to the previously added node.
 * @details the next pointer of the first added @ref dptX_node "node"
 * will point to NULL, indicating that this is the end of the list.
 */

/**
 * @brief Node of a @ref dpt1_list.
 */
struct __attribute__ ((__packed__)) dpt1_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt1.
	 */
	struct dpt1 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt1_node.
	 */
	struct dpt1_node* next;
};

/**
 * @brief Node of a @ref dpt7_list.
 */
struct __attribute__ ((__packed__)) dpt7_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt7.
	 */
	struct dpt7 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt7_node.
	 */
	struct dpt7_node* next;
};

/**
 * @brief Node of a @ref dpt10_list.
 */
struct __attribute__ ((__packed__)) dpt10_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt10.
	 */
	struct dpt10 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt10_node.
	 */
	struct dpt10_node* next;
};

/**
 * @brief Node of a @ref dpt12_list.
 */
struct __attribute__ ((__packed__)) dpt12_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt12.
	 */
	struct dpt12 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt12_node.
	 */
	struct dpt12_node* next;
};

/**
 * @brief Node of a @ref dpt215_list.
 */
struct __attribute__ ((__packed__)) dpt215_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt215.
	 */
	struct dpt215 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt215_node.
	 */
	struct dpt215_node* next;
};

/**
 * @brief Node of a @ref dpt212_list.
 */
struct __attribute__ ((__packed__)) dpt212_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt212.
	 */
	struct dpt212 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt212_node.
	 */
	struct dpt212_node* next;
};

/**
 * @brief Node of a @ref dpt19_list.
 */
struct __attribute__ ((__packed__)) dpt19_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt19.
	 */
	struct dpt19 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt19_node.
	 */
	struct dpt19_node* next;
};

/**
 * @brief Node of a @ref dpt16_list.
 */
struct __attribute__ ((__packed__)) dpt16_node {
	/**
	 * @ingroup dataStruct
	 * @brief A struct containing all the data of a dpt16.
	 */
	struct dpt16 dataStruct;

	/**
	 * @ingroup next
	 * @brief Points to the previously added @ref dpt16_node.
	 */
	struct dpt16_node* next;
};
///@}

/**
 * @defgroup dptX_list
 * @brief A list containing @ref dptX_node s.
 * @details It actually is a pointer to a list containing @ref dptX_node s.
 * @{
 */
typedef struct dpt1_node* dpt1_list;
typedef struct dpt7_node* dpt7_list;
typedef struct dpt10_node* dpt10_list;
typedef struct dpt12_node* dpt12_list;
typedef struct dpt215_node* dpt215_list;
typedef struct dpt212_node* dpt212_list;
typedef struct dpt19_node* dpt19_list;
typedef struct dpt16_node* dpt16_list;
///@}

// Creates a list with one node
dpt1_list* dpt1CreateList(const struct dpt1 firstDataStruct);
dpt7_list* dpt7CreateList(const struct dpt7 firstDataStruct);
dpt10_list* dpt10CreateList(const struct dpt10 firstDataStruct);
dpt12_list* dpt12CreateList(const struct dpt12 firstDataStruct);
dpt215_list* dpt215CreateList(const struct dpt215 firstDataStruct);
dpt212_list* dpt212CreateList(const struct dpt212 firstDataStruct);
dpt19_list* dpt19CreateList(const struct dpt19 firstDataStruct);
dpt16_list* dpt16CreateList(const struct dpt16 firstDataStruct);

// Creates an empty list
dpt1_list* dpt1CreateEmptyList();
dpt7_list* dpt7CreateEmptyList();
dpt10_list* dpt10CreateEmptyList();
dpt12_list* dpt12CreateEmptyList();
dpt215_list* dpt215CreateEmptyList();
dpt212_list* dpt212CreateEmptyList();
dpt19_list* dpt19CreateEmptyList();
dpt16_list* dpt16CreateEmptyList();

// returns the size of the list
short dpt1SizeOfList(const dpt1_list* list);
short dpt7SizeOfList(const dpt7_list* list);
short dpt10SizeOfList(const dpt10_list* list);
short dpt12SizeOfList(const dpt12_list* list);
short dpt215SizeOfList(const dpt215_list* list);
short dpt212SizeOfList(const dpt212_list* list);
short dpt19SizeOfList(const dpt19_list* list);
short dpt16SizeOfList(const dpt16_list* list);

// This function frees all the nodes in the list
//  and frees the list itself, hence it can no 
//  longer be used
void dpt1FreeList(dpt1_list* list);
void dpt7FreeList(dpt7_list* list);
void dpt10FreeList(dpt10_list* list);
void dpt12FreeList(dpt12_list* list);
void dpt215FreeList(dpt215_list* list);
void dpt212FreeList(dpt212_list* list);
void dpt19FreeList(dpt19_list* list);
void dpt16FreeList(dpt16_list* list);

// This function frees all the nodes in the list
//  and sets the list to NULL
void dpt1EmptyList(dpt1_list* list);
void dpt7EmptyList(dpt7_list* list);
void dpt10EmptyList(dpt10_list* list);
void dpt12EmptyList(dpt12_list* list);
void dpt215EmptyList(dpt215_list* list);
void dpt212EmptyList(dpt212_list* list);
void dpt19EmptyList(dpt19_list* list);
void dpt16EmptyList(dpt16_list* list);

// This function checks if the list is empty
//  returns 1 when empty
//  returns 0 when not empty
unsigned char dpt1CheckEmpty(const dpt1_list* list);
unsigned char dpt7CheckEmpty(const dpt7_list* list);
unsigned char dpt10CheckEmpty(const dpt10_list* list);
unsigned char dpt12CheckEmpty(const dpt12_list* list);
unsigned char dpt215CheckEmpty(const dpt215_list* list);
unsigned char dpt212CheckEmpty(const dpt212_list* list);
unsigned char dpt19CheckEmpty(const dpt19_list* list);
unsigned char dpt16CheckEmpty(const dpt16_list* list);

// This function adds new nodes to the list
char dpt1PushList(dpt1_list* list, const struct dpt1 newDataStruct);
char dpt7PushList(dpt7_list* list, const struct dpt7 newDataStruct);
char dpt10PushList(dpt10_list* list, const struct dpt10 newDataStruct);
char dpt12PushList(dpt12_list* list, const struct dpt12 newDataStruct);
char dpt215PushList(dpt215_list* list,
		const struct dpt215 newDataStruct);
char dpt212PushList(dpt212_list* list,
		const struct dpt212 newDataStruct);
char dpt19PushList(dpt19_list* list, const struct dpt19 newDataStruct);
char dpt16PushList(dpt16_list* list, const struct dpt16 newDataStruct);

// This function frees the node that was last added
//  and sets list corresponding
struct dpt1 dpt1PopLast(dpt1_list* list);
struct dpt7 dpt7PopLast(dpt7_list* list);
struct dpt10 dpt10PopLast(dpt10_list* list);
struct dpt12 dpt12PopLast(dpt12_list* list);
struct dpt215 dpt215PopLast(dpt215_list* list);
struct dpt212 dpt212PopLast(dpt212_list* list);
struct dpt19 dpt19PopLast(dpt19_list* list);
struct dpt16 dpt16PopLast(dpt16_list* list);

// This function frees the node that was first added
//  and sets next of the second node to NULL
struct dpt1 dpt1PopFirst(dpt1_list* list);
struct dpt7 dpt7PopFirst(dpt7_list* list);
struct dpt10 dpt10PopFirst(dpt10_list* list);
struct dpt12 dpt12PopFirst(dpt12_list* list);
struct dpt215 dpt215PopFirst(dpt215_list* list);
struct dpt212 dpt212PopFirst(dpt212_list* list);
struct dpt19 dpt19PopFirst(dpt19_list* list);
struct dpt16 dpt16PopFirst(dpt16_list* list);

// This function returns the data struct of the first added
//  node, and sets the first node as last node
struct dpt1 dpt1FirstToLast(dpt1_list* list);
struct dpt7 dpt7FirstToLast(dpt7_list* list);
struct dpt10 dpt10FirstToLast(dpt10_list* list);
struct dpt12 dpt12FirstToLast(dpt12_list* list);
struct dpt215 dpt215FirstToLast(dpt215_list* list);
struct dpt212 dpt212FirstToLast(dpt212_list* list);
struct dpt19 dpt19FirstToLast(dpt19_list* list);
struct dpt16 dpt16FirstToLast(dpt16_list* list);

// This function returns the data struct of the first added
//  node in list1. This node will be freed, and added to list 2
struct dpt1 dpt1FirstToOtherList(dpt1_list* list1, dpt1_list* list2);
struct dpt7 dpt7FirstToOtherList(dpt7_list* list1, dpt7_list* list2);
struct dpt10 dpt10FirstToOtherList(dpt10_list* list1,
		dpt10_list* list2);
struct dpt12 dpt12FirstToOtherList(dpt12_list* list1,
		dpt12_list* list2);
struct dpt215 dpt215FirstToOtherList(dpt215_list* list1,
		dpt215_list* list2);
struct dpt212 dpt212FirstToOtherList(dpt212_list* list1,
		dpt212_list* list2);
struct dpt19 dpt19FirstToOtherList(dpt19_list* list1,
		dpt19_list* list2);
struct dpt16 dpt16FirstToOtherList(dpt16_list* list1,
		dpt16_list* list2);

// This function returns the data struct of
//  the last added node
struct dpt1 dpt1LastData(const dpt1_list* list);
struct dpt7 dpt7LastData(const dpt7_list* list);
struct dpt10 dpt10LastData(const dpt10_list* list);
struct dpt12 dpt12LastData(const dpt12_list* list);
struct dpt215 dpt215LastData(const dpt215_list* list);
struct dpt212 dpt212LastData(const dpt212_list* list);
struct dpt19 dpt19LastData(const dpt19_list* list);
struct dpt16 dpt16LastData(const dpt16_list* list);

// This function returns the data struct of
//  the first added node
struct dpt1 dpt1FirstData(const dpt1_list* list);
struct dpt7 dpt7FirstData(const dpt7_list* list);
struct dpt10 dpt10FirstData(const dpt10_list* list);
struct dpt12 dpt12FirstData(const dpt12_list* list);
struct dpt215 dpt215FirstData(const dpt215_list* list);
struct dpt212 dpt212FirstData(const dpt212_list* list);
struct dpt19 dpt19FirstData(const dpt19_list* list);
struct dpt16 dpt16FirstData(const dpt16_list* list);

// This function returns the first added node
struct dpt1_node* dpt1FirstNode(const dpt1_list* list);
struct dpt7_node* dpt7FirstNode(const dpt7_list* list);
struct dpt10_node* dpt10FirstNode(const dpt10_list* list);
struct dpt12_node* dpt12FirstNode(const dpt12_list* list);
struct dpt215_node* dpt215FirstNode(const dpt215_list* list);
struct dpt212_node* dpt212FirstNode(const dpt212_list* list);
struct dpt19_node* dpt19FirstNode(const dpt19_list* list);
struct dpt16_node* dpt16FirstNode(const dpt16_list* list);

#endif // MYSTORAGE_H
