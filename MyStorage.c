#include "MyStorage.h"
#include <stdlib.h>
#include <stdio.h>

// - CreateList ---------------------------------------------------------------
/**
 * @defgroup dptXCreateList Create list
 * @brief Creates a @ref dptX_list "list" with one @ref dptX_node "node".
 * @details Creates a list with one node.
 * @param[in] firstDataStruct The @ref dataStruct of the first node.
 * @returns Pointer to the created list.
 * @warning If the pointer was already pointing to a list, this list will not be freed.
 * @warning This function does not check if the memory allocation succeeded.
 * @{
 */
/**
 * @name dptXCreateList
 * @brief Creates a @ref dptX_list "list" with one @ref dptX_node "node".
 * @param[in] firstDataStruct The @ref dataStruct of the first node.
 * @returns Pointer to the created list.
 * @warning If the pointer was already pointing to a list, this list will not be freed.
 * @warning This function does not check if the memory allocation succeeded.
 * @{
 */

/** @details Creates a @ref dpt1_list with \p firstDataStruct as the dpt1_node::dataStruct
 * of the first dpt1_node.
 */
dpt1_list* dpt1CreateList(const struct dpt1 firstDataStruct)
{
	struct dpt1_node* newNode;

	dpt1_list* newList = malloc(sizeof(dpt1_list));
	*newList = malloc(sizeof(struct dpt1_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt7_list with \p firstDataStruct as the dpt7_node::dataStruct
 * of the first dpt7_node.
 */
dpt7_list* dpt7CreateList(const struct dpt7 firstDataStruct)
{
	struct dpt7_node* newNode;

	dpt7_list* newList = malloc(sizeof(dpt7_list));
	*newList = malloc(sizeof(struct dpt7_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt10_list with \p firstDataStruct as the dpt10_node::dataStruct
 * of the first dpt10_node.
 */
dpt10_list* dpt10CreateList(const struct dpt10 firstDataStruct)
{
	struct dpt10_node* newNode;

	dpt10_list* newList = malloc(sizeof(dpt10_list));
	*newList = malloc(sizeof(struct dpt10_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt12_list with \p firstDataStruct as the dpt12_node::dataStruct
 * of the first dpt12_node.
 */
dpt12_list* dpt12CreateList(const struct dpt12 firstDataStruct)
{
	struct dpt12_node* newNode;

	dpt12_list* newList = malloc(sizeof(dpt12_list));
	*newList = malloc(sizeof(struct dpt12_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt215_list with \p firstDataStruct as the dpt215_node::dataStruct
 * of the first dpt215_node.
 */
dpt215_list* dpt215CreateList(const struct dpt215 firstDataStruct)
{
	struct dpt215_node* newNode;

	dpt215_list* newList = malloc(sizeof(dpt215_list));
	*newList = malloc(sizeof(struct dpt215_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt212_list with \p firstDataStruct as the dpt212_node::dataStruct
 * of the first dpt212_node.
 */
dpt212_list* dpt212CreateList(const struct dpt212 firstDataStruct)
{
	struct dpt212_node* newNode;

	dpt212_list* newList = malloc(sizeof(dpt212_list));
	*newList = malloc(sizeof(struct dpt212_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt19_list with \p firstDataStruct as the dpt19_node::dataStruct
 * of the first dpt19_node.
 */
dpt19_list* dpt19CreateList(const struct dpt19 firstDataStruct)
{
	struct dpt19_node* newNode;

	dpt19_list* newList = malloc(sizeof(dpt19_list));
	*newList = malloc(sizeof(struct dpt19_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}

/** @details Creates a @ref dpt16_list with \p firstDataStruct as the dpt16_node::dataStruct
 * of the first dpt16_node.
 */
dpt16_list* dpt16CreateList(const struct dpt16 firstDataStruct)
{
	struct dpt16_node* newNode;

	dpt16_list* newList = malloc(sizeof(dpt16_list));
	*newList = malloc(sizeof(struct dpt16_node));

	newNode = *newList;
	newNode->dataStruct = firstDataStruct;
	newNode->next = NULL;
	return newList;
}
///@}
///@}

// - CreateEmptyList ----------------------------------------------------------
/**
 * @defgroup dptXCreateEmptyList Create empty list
 * @brief Configures a @ref dptX_list "list".
 * @details Creates an empty list.
 * @param none
 * @returns Pointer to the created list.
 * @warning If the pointer was already pointing to a list, this list will not be freed.
 * @warning This function does not check if the memory allocation succeeded.
 * @{
 */
/**
 * @name dptXCreateEmptyList
 * @brief Configures a @ref dptX_list "list".
 * @param none
 * @returns Pointer to the created list.
 * @warning If the pointer was already pointing to a list, this list will not be freed.
 * @warning This function does not check if the memory allocation succeeded.
 * @{
 */

/// @details Creates an empty @ref dpt1_list.
dpt1_list* dpt1CreateEmptyList()
{
	dpt1_list* newList = malloc(sizeof(dpt1_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt7_list.
dpt7_list* dpt7CreateEmptyList()
{
	dpt7_list* newList = malloc(sizeof(dpt7_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt10_list.
dpt10_list* dpt10CreateEmptyList()
{
	dpt10_list* newList = malloc(sizeof(dpt10_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt12_list.
dpt12_list* dpt12CreateEmptyList()
{
	dpt12_list* newList = malloc(sizeof(dpt12_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt215_list.
dpt215_list* dpt215CreateEmptyList()
{
	dpt215_list* newList = malloc(sizeof(dpt215_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt212_list.
dpt212_list* dpt212CreateEmptyList()
{
	dpt212_list* newList = malloc(sizeof(dpt212_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt19_list.
dpt19_list* dpt19CreateEmptyList()
{
	dpt19_list* newList = malloc(sizeof(dpt19_list));
	*newList = NULL;
	return newList;
}

/// @details Creates an empty @ref dpt16_list.
dpt16_list* dpt16CreateEmptyList()
{
	dpt16_list* newList = malloc(sizeof(dpt16_list));
	*newList = NULL;
	return newList;
}
///@}
///@}

// - Size of list -------------------------------------------------------------
/**
 * @defgroup dptXSizeOfList Size of list
 * @brief Gets the size of \p list.
 * @details Gets the size of a \p list.
 * @param[in] list The @ref dptX_list "list" of which the size will be counted.
 * @return Size of \p list.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXSizeOfList
 * @brief Gets the size of \p list.
 * @param[in] list The @ref dptX_list "list" of which the size will be counted.
 * @return Size of \p list.
 * @pre \p list must be created first.
 * @{
 */

/// @details Gets the size of a @ref dpt1_list.
short dpt1SizeOfList(const dpt1_list* list)
{
	struct dpt1_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt7_list.
short dpt7SizeOfList(const dpt7_list* list)
{
	struct dpt7_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt10_list.
short dpt10SizeOfList(const dpt10_list* list)
{
	struct dpt10_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt12_list.
short dpt12SizeOfList(const dpt12_list* list)
{
	struct dpt12_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt215_list.
short dpt215SizeOfList(const dpt215_list* list)
{
	struct dpt215_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt212_list.
short dpt212SizeOfList(const dpt212_list* list)
{
	struct dpt212_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt19_list.
short dpt19SizeOfList(const dpt19_list* list)
{
	struct dpt19_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}

/// @details Gets the size of a @ref dpt16_list.
short dpt16SizeOfList(const dpt16_list* list)
{
	struct dpt16_node* curr = *list;
	short size = 1;

	// List is empty
	if (NULL == curr) {
		return 0;
	}

	// List contains at least 1 node
	while (NULL != curr->next) {
		size += 1;
		curr = curr->next;
	}
	return size;
}
///@}
///@}

// - FreeList -----------------------------------------------------------------
/**
 * @defgroup dptXFreeList Free list
 * @brief Frees the entire \p list.
 * @details Frees all nodes in \p list.\n
 * Frees \p list itself.
 * @param[in,out] list The @ref dptX_list "list" that will be freed.
 * @warning Since \p list is freed you have to call
 * @ref dptXCreateList() or @ref dptXCreateEmptyList() again to use the list.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXFreeList
 * @brief Frees the entire \p list.
 * @param[in,out] list The @ref dptX_list "list" that will be freed.
 * @warning Since \p list is freed you have to call
 * @ref dptXCreateList() or @ref dptXCreateEmptyList() again to use the list.
 * @pre \p list must be created first.
 * @{
 */

/// @details Frees the @ref dpt1_list.
void dpt1FreeList(dpt1_list* list)
{
	struct dpt1_node* curr = *list;
	struct dpt1_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt7_list.
void dpt7FreeList(dpt7_list* list)
{
	struct dpt7_node* curr = *list;
	struct dpt7_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt10_list.
void dpt10FreeList(dpt10_list* list)
{
	struct dpt10_node* curr = *list;
	struct dpt10_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt12_list.
void dpt12FreeList(dpt12_list* list)
{
	struct dpt12_node* curr = *list;
	struct dpt12_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt215_list.
void dpt215FreeList(dpt215_list* list)
{
	struct dpt215_node* curr = *list;
	struct dpt215_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt212_list.
void dpt212FreeList(dpt212_list* list)
{
	struct dpt212_node* curr = *list;
	struct dpt212_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt19_list.
void dpt19FreeList(dpt19_list* list)
{
	struct dpt19_node* curr = *list;
	struct dpt19_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}

/// @details Frees the @ref dpt16_list.
void dpt16FreeList(dpt16_list* list)
{
	struct dpt16_node* curr = *list;
	struct dpt16_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(list);
}
///@}
///@}

// - EmptyList ----------------------------------------------------------------
/**
 * @defgroup dptXEmptyList Empty list
 * @brief Empties the entire \p list.
 * @details Frees all nodes in \p list.
 * Makes \p list point to NULL.
 * @param[in,out] list The @ref dptX_list "list" that will be emptied.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXEmptyList
 * @brief Empties the entire \p list.
 * @param[in,out] list The @ref dptX_list "list" that will be emptied.
 * @pre \p list must be created first.
 * @{
 */

/// @details Empties the @ref dpt1_list.
void dpt1EmptyList(dpt1_list* list)
{
	struct dpt1_node* curr = *list;
	struct dpt1_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt7_list.
void dpt7EmptyList(dpt7_list* list)
{
	struct dpt7_node* curr = *list;
	struct dpt7_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt10_list.
void dpt10EmptyList(dpt10_list* list)
{
	struct dpt10_node* curr = *list;
	struct dpt10_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt12_list.
void dpt12EmptyList(dpt12_list* list)
{
	struct dpt12_node* curr = *list;
	struct dpt12_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt215_list.
void dpt215EmptyList(dpt215_list* list)
{
	struct dpt215_node* curr = *list;
	struct dpt215_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt212_list.
void dpt212EmptyList(dpt212_list* list)
{
	struct dpt212_node* curr = *list;
	struct dpt212_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt19_list.
void dpt19EmptyList(dpt19_list* list)
{
	struct dpt19_node* curr = *list;
	struct dpt19_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}

/// @details Empties the @ref dpt16_list.
void dpt16EmptyList(dpt16_list* list)
{
	struct dpt16_node* curr = *list;
	struct dpt16_node* next;

	while (NULL != curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}

	*list = NULL;
}
///@}
///@}

// - CheckEmpty ---------------------------------------------------------------
/**
 * @defgroup dptXCheckEmpty Check Empty
 * @brief Checks if \p list is empty.
 * @details Checks if \p list is empty.
 * @param[in] list The @ref dptX_list "list" that will be checked.
 * @retval 1 if \p list is empty.
 * @retval 0 if \p list is not empty.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXCheckEmpty
 * @brief Checks if \p list is empty.
 * @param[in] list The @ref dptX_list "list" that will be checked.
 * @retval 1 if \p list is empty.
 * @retval 0 if \p list is not empty.
 * @pre \p list must be created first.
 * @{
 */

/// @details Checks if the @ref dpt1_list is empty.
unsigned char dpt1CheckEmpty(const dpt1_list* list)
{
	struct dpt1_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt7_list is empty.
unsigned char dpt7CheckEmpty(const dpt7_list* list)
{
	struct dpt7_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt10_list is empty.
unsigned char dpt10CheckEmpty(const dpt10_list* list)
{
	struct dpt10_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt12_list is empty.
unsigned char dpt12CheckEmpty(const dpt12_list* list)
{
	struct dpt12_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt215_list is empty.
unsigned char dpt215CheckEmpty(const dpt215_list* list)
{
	struct dpt215_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt212_list is empty.
unsigned char dpt212CheckEmpty(const dpt212_list* list)
{
	struct dpt212_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt19_list is empty.
unsigned char dpt19CheckEmpty(const dpt19_list* list)
{
	struct dpt19_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}

/// @details Checks if the @ref dpt16_list is empty.
unsigned char dpt16CheckEmpty(const dpt16_list* list)
{
	struct dpt16_node* curr = *list;
	if (NULL == curr) {
		return 1;
	}
	return 0;
}
///@}
///@}

// - PushList -----------------------------------------------------------------
/**
 * @defgroup dptXPushList Push list
 * @brief Adds a new @ref dptX_node "node" to \p list.
 * @details Adds a new node with \p newDataStruct as @ref dataStruct at the end of \p list.
 * @param[in,out] list The list in which the new node will be added.
 * @param[in] newDataStruct This datastruct shall be part of the new node.
 * @retval 0 On succesfull memory allocation.
 * @retval -1 When memory allocation failed.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXPushList
 * @brief Adds a new @ref dptX_node "node" to \p list.
 * @param[in,out] list The list in which the new node will be added.
 * @param[in] newDataStruct This datastruct shall be part of the new node.
 * @retval 0 On succesfull memory allocation.
 * @retval -1 When memory allocation failed.
 * @pre \p list must be created first.
 * @{
 */

/** @details Adds a new dpt1_node with \p newDataStruct as dpt1_node::dataStruct
 * at the end of \p list.
 */
char dpt1PushList(dpt1_list* list, const struct dpt1 newDataStruct)
{
	struct dpt1_node* newNode = malloc(sizeof(struct dpt1_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt7_node with \p newDataStruct as dpt7_node::dataStruct
 * at the end of \p list.
 */
char dpt7PushList(dpt7_list* list, const struct dpt7 newDataStruct)
{
	struct dpt7_node* newNode = malloc(sizeof(struct dpt7_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt10_node with \p newDataStruct as dpt10_node::dataStruct
 * at the end of \p list.
 */
char dpt10PushList(dpt10_list* list, const struct dpt10 newDataStruct)
{
	struct dpt10_node* newNode = malloc(sizeof(struct dpt10_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt12_node with \p newDataStruct as dpt12_node::dataStruct
 * at the end of \p list.
 */
char dpt12PushList(dpt12_list* list, const struct dpt12 newDataStruct)
{
	struct dpt12_node* newNode = malloc(sizeof(struct dpt12_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt215_node with \p newDataStruct as dpt215_node::dataStruct
 * at the end of \p list.
 */
char dpt215PushList(dpt215_list* list,
		const struct dpt215 newDataStruct)
{
	struct dpt215_node* newNode = malloc(sizeof(struct dpt215_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt212_node with \p newDataStruct as dpt212_node::dataStruct
 * at the end of \p list.
 */
char dpt212PushList(dpt212_list* list,
		const struct dpt212 newDataStruct)
{
	struct dpt212_node* newNode = malloc(sizeof(struct dpt212_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt19_node with \p newDataStruct as dpt19_node::dataStruct
 * at the end of \p list.
 */
char dpt19PushList(dpt19_list* list, const struct dpt19 newDataStruct)
{
	struct dpt19_node* newNode = malloc(sizeof(struct dpt19_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}

/** @details Adds a new dpt16_node with \p newDataStruct as dpt16_node::dataStruct
 * at the end of \p list.
 */
char dpt16PushList(dpt16_list* list, const struct dpt16 newDataStruct)
{
	struct dpt16_node* newNode = malloc(sizeof(struct dpt16_node));

	if (NULL == newNode) {
		return -1;
	}

	newNode->dataStruct = newDataStruct;
	newNode->next = *list;
	*list = newNode;
	return 0;
}
///@}
///@}

// - popLast ------------------------------------------------------------------
/**
 * @defgroup dptXPopLast Pop last
 * @brief Removes the last @ref dptX_node "node" of \p list.
 * @details Removes the last node of \p list.
 * @param[in,out] list The list of which the last node will be removed.
 * @returns The @ref dataStruct of the removed node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXPopLast
 * @brief Removes the last @ref dptX_node "node" of \p list.
 * @param[in,out] list The list of which the last node will be removed.
 * @returns The @ref dataStruct of the removed node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */

/// @details Removes the last dpt1_node of \p list.
struct dpt1 dpt1PopLast(dpt1_list* list)
{
	struct dpt1 popped_data = { 0, 0, 0 };
	struct dpt1_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt7_node of \p list.
struct dpt7 dpt7PopLast(dpt7_list* list)
{
	struct dpt7 popped_data = { { 0 }, 0, 0 };
	struct dpt7_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt10_node of \p list.
struct dpt10 dpt10PopLast(dpt10_list* list)
{
	struct dpt10 popped_data = { { 0 }, 0, 0 };
	struct dpt10_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt12_node of \p list.
struct dpt12 dpt12PopLast(dpt12_list* list)
{
	struct dpt12 popped_data = { 0, 0, 0 };
	struct dpt12_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt215_node of \p list.
struct dpt215 dpt215PopLast(dpt215_list* list)
{
	struct dpt215 popped_data = { 0, 0, 0 };
	struct dpt215_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt212_node of \p list.
struct dpt212 dpt212PopLast(dpt212_list* list)
{
	struct dpt212 popped_data = { 0, 0, 0 };
	struct dpt212_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt19_node of \p list.
struct dpt19 dpt19PopLast(dpt19_list* list)
{
	struct dpt19 popped_data = { 0, 0, 0 };
	struct dpt19_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}

/// @details Removes the last dpt16_node of \p list.
struct dpt16 dpt16PopLast(dpt16_list* list)
{
	struct dpt16 popped_data = { 0, 0, 0 };
	struct dpt16_node* head = *list;

	if (NULL == head) {
		return popped_data;
	}

	popped_data = head->dataStruct;
	*list = head->next;

	free(head);

	return popped_data;
}
///@}
///@}

// - popFirst -----------------------------------------------------------------
/**
 * @defgroup dptXPopFirst Pop first
 * @brief Removes the first @ref dptX_node "node" of \p list.
 * @details Removes the first node of \p list.
 * @param[in,out] list The @ref dptX_list "list" of which the
 * first @ref dptX_node "node" will be removed.
 * @returns The @ref dataStruct of the removed node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXPopFirst
 * @brief Removes the first @ref dptX_node "node" of \p list.
 * @param[in,out] list The @ref dptX_list "list" of which the
 * first @ref dptX_node "node" will be removed.
 * @returns The @ref dataStruct of the removed node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */

/// @details Removes the first dpt1_node of \p list.
struct dpt1 dpt1PopFirst(dpt1_list* list)
{
	struct dpt1 popped_data = { 0, 0, 0 };
	struct dpt1_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt7_node of \p list.
struct dpt7 dpt7PopFirst(dpt7_list* list)
{
	struct dpt7 popped_data = { 0, 0, 0 };
	struct dpt7_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt10_node of \p list.
struct dpt10 dpt10PopFirst(dpt10_list* list)
{
	struct dpt10 popped_data = { 0, 0, 0 };
	struct dpt10_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt12_node of \p list.
struct dpt12 dpt12PopFirst(dpt12_list* list)
{
	struct dpt12 popped_data = { 0, 0, 0 };
	struct dpt12_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt215_node of \p list.
struct dpt215 dpt215PopFirst(dpt215_list* list)
{
	struct dpt215 popped_data = { 0, 0, 0 };
	struct dpt215_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt212_node of \p list.
struct dpt212 dpt212PopFirst(dpt212_list* list)
{
	struct dpt212 popped_data = { 0, 0, 0 };
	struct dpt212_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt19_node of \p list.
struct dpt19 dpt19PopFirst(dpt19_list* list)
{
	struct dpt19 popped_data = { 0, 0, 0 };
	struct dpt19_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}

/// @details Removes the first dpt16_node of \p list.
struct dpt16 dpt16PopFirst(dpt16_list* list)
{
	struct dpt16 popped_data = { 0, 0, 0 };
	struct dpt16_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return popped_data;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		popped_data = curr->dataStruct;
		free(curr);
		*list = NULL;
		return popped_data;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	popped_data = curr->next->dataStruct;
	free(curr->next);
	curr->next = NULL;
	return popped_data;
}
///@}
///@}

// - FirstToLast --------------------------------------------------------------
/**
 * @defgroup dptXFirstToLast First to last
 * @brief Moves the first @ref dptX_node "node" of \p list to the end of \p list.
 * @details Sets the @ref next of the first node to the address of \p list
 * (which is the end).\n Sets the next pointer of the second node to NULL.
 * @param[in,out] list The list of which the first node will be moved to the end.
 * @returns The @ref dataStruct of the moved node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */
/**
 * @name dptXFirstToLast
 * @brief Moves the first @ref dptX_node "node" of \p list to the end of \p list.
 * @param[in,out] list The list of which the first node will be moved to the end.
 * @returns The @ref dataStruct of the moved node.
 * @retval {0, 0, 0} if list is empty.
 * @pre \p list must be created first.
 * @{
 */

/**
 * @details Sets the @ref dpt1_node::next "next pointer" of the first dpt1_node
 * to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt1_node to NULL.
 */
struct dpt1 dpt1FirstToLast(dpt1_list* list)
{
	struct dpt1 dat = { 0, 0, 0 };
	struct dpt1_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt7_node::next "next pointer" of the first dpt7_node
 * to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt7_node to NULL.
 */
struct dpt7 dpt7FirstToLast(dpt7_list* list)
{
	struct dpt7 dat = { 0, 0, 0 };
	struct dpt7_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt7_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt7_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt10_node::next "next pointer" of the first
 * dpt10_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt10_node to NULL.
 */
struct dpt10 dpt10FirstToLast(dpt10_list* list)
{
	struct dpt10 dat = { 0, 0, 0 };
	struct dpt10_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt10_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt10_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt12_node::next "next pointer" of the first
 * dpt12_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt12_node to NULL.
 */
struct dpt12 dpt12FirstToLast(dpt12_list* list)
{
	struct dpt12 dat = { 0, 0, 0 };
	struct dpt12_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt12_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt12_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt215_node::next "next pointer" of the first
 * dpt215_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt215_node to NULL.
 */
struct dpt215 dpt215FirstToLast(dpt215_list* list)
{
	struct dpt215 dat = { 0, 0, 0 };
	struct dpt215_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt215_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt215_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt212_node::next "next pointer" of the first
 * dpt212_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt212_node to NULL.
 */
struct dpt212 dpt212FirstToLast(dpt212_list* list)
{
	struct dpt212 dat = { 0, 0, 0 };
	struct dpt212_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt212_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt212_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt19_node::next "next pointer" of the first
 * dpt19_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt19_node to NULL.
 */
struct dpt19 dpt19FirstToLast(dpt19_list* list)
{
	struct dpt19 dat = { 0, 0, 0 };
	struct dpt19_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt19_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt19_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt16_node::next "next pointer" of the first
 * dpt16_node to the address of \p list (which is the end).\n
 * Sets the next pointer of the second dpt16_node to NULL.
 */
struct dpt16 dpt16FirstToLast(dpt16_list* list)
{
	struct dpt16 dat = { 0, 0, 0 };
	struct dpt16_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt16_node
	if (NULL == curr->next) {
		return curr->dataStruct;
	}

	// List contains multiple dpt16_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
	return dat;
}
///@}
///@}

// - First to other list ------------------------------------------------------
/**
 * @defgroup dptXFirstToOtherList First to other list
 * @brief Moves the first @ref dptX_node "node" of \p list1 to the end of \p list2.
 * @details Sets the @ref next of the first node in \p list1
 * to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second node in \p list1.
 * \n Sets the next pointer of the second dpt1_node in \p list1 to NULL.
 * @param[in,out] list1 The list of which the first node will be removed.
 * @param[in,out] list2 The list to which the removed node will be added.
 * @returns The @ref dataStruct of the moved node.
 * @retval {0, 0, 0} if \p list1 is empty.
 * @pre \p list1 and \p list2 must be created first.
 * @pre \p list1 must not be empty.\n
 * Otherwise no node will be added to \p list2.
 * @{
 */
/**
 * @name dptXFirstToOtherList
 * @brief Moves the first @ref dptX_node "node" of \p list1 to the end of \p list2.
 * @param[in,out] list1 The list of which the first node will be removed.
 * @param[in,out] list2 The list to which the removed node will be added.
 * @returns The @ref dataStruct of the moved node.
 * @retval {0, 0, 0} if \p list1 is empty.
 * @pre \p list1 and \p list2 must be created first.
 * @pre \p list1 must not be empty.\n
 * Otherwise no node will be added to \p list2.
 * @{
 */

/**
 * @details Sets the @ref dpt1_node::next "next pointer" of the first dpt1_node
 * in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt1_node in \p list1.\n
 * Sets the next pointer of the second dpt1_node in \p list1 to NULL.
 */
struct dpt1 dpt1FirstToOtherList(dpt1_list* list1, dpt1_list* list2)
{
	struct dpt1 dat = { 0, 0, 0 };
	struct dpt1_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt1_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt1_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt7_node::next "next pointer" of the first dpt7_node
 * in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt7_node in \p list1.
 * \n Sets the next pointer of the second dpt7_node in \p list1 to NULL.
 */
struct dpt7 dpt7FirstToOtherList(dpt7_list* list1, dpt7_list* list2)
{
	struct dpt7 dat = { 0, 0, 0 };
	struct dpt7_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt7_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt7_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt10_node::next "next pointer" of the first
 * dpt10_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt10_node in \p list1.
 * \n Sets the next pointer of the second dpt10_node in \p list1 to NULL.
 */
struct dpt10 dpt10FirstToOtherList(dpt10_list* list1,
		dpt10_list* list2)
{
	struct dpt10 dat = { 0, 0, 0 };
	struct dpt10_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt10_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt10_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt12_node::next "next pointer" of the first
 * dpt12_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt12_node in \p list1.
 * \n Sets the next pointer of the second dpt12_node in \p list1 to NULL.
 */
struct dpt12 dpt12FirstToOtherList(dpt12_list* list1,
		dpt12_list* list2)
{
	struct dpt12 dat = { 0, 0, 0 };
	struct dpt12_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt12_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt12_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt215_node::next "next pointer" of the first
 * dpt215_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt215_node in \p list1.
 * \n Sets the next pointer of the second dpt215_node in \p list1 to NULL.
 */
struct dpt215 dpt215FirstToOtherList(dpt215_list* list1,
		dpt215_list* list2)
{
	struct dpt215 dat = { 0, 0, 0 };
	struct dpt215_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt215_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt215_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt212_node::next "next pointer" of the first
 * dpt212_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt212_node in \p list1.
 * \n Sets the next pointer of the second dpt212_node in \p list1 to NULL.
 */
struct dpt212 dpt212FirstToOtherList(dpt212_list* list1,
		dpt212_list* list2)
{
	struct dpt212 dat = { 0, 0, 0 };
	struct dpt212_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt212_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt212_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt19_node::next "next pointer" of the first
 * dpt19_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt19_node in \p list1.
 * \n Sets the next pointer of the second dpt19_node in \p list1 to NULL.
 */
struct dpt19 dpt19FirstToOtherList(dpt19_list* list1,
		dpt19_list* list2)
{
	struct dpt19 dat = { 0, 0, 0 };
	struct dpt19_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt19_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt19_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}

/**
 * @details Sets the @ref dpt16_node::next "next pointer" of the first
 * dpt16_node in \p list1 to the address of \p list2 (which is the end).\n
 * Sets \p list2 to the next pointer of the second dpt16_node in \p list1.
 * \n Sets the next pointer of the second dpt16_node in \p list1 to NULL.
 */
struct dpt16 dpt16FirstToOtherList(dpt16_list* list1,
		dpt16_list* list2)
{
	struct dpt16 dat = { 0, 0, 0 };
	struct dpt16_node* curr = *list1;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List only contains one dpt16_node
	if (NULL == curr->next) {
		dat = curr->dataStruct;
		curr->next = *list2;
		*list2 = *list1;
		*list1 = NULL;
		return dat;
	}

	// List contains multiple dpt16_nodes
	while (NULL != curr->next->next) {
		curr = curr->next;
	}
	dat = curr->next->dataStruct;
	curr->next->next = *list2;
	*list2 = curr->next;
	curr->next = NULL;
	return dat;
}
///@}
///@}

// - LastData -----------------------------------------------------------------
/**
 * @defgroup dptXLastData Last data
 * @brief Gets the @ref dataStruct of the last added @ref dptX_node "node" in \p list.
 * @details The dataStruct of the last added node will be returned.
 * @param[in] list The @ref dptX_list "list" of which the last dataStruct is needed.
 * @returns The dataStruct of the last node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */
/**
 * @name dptXLastData
 * @brief Gets the @ref dataStruct of the last added @ref dptX_node "node" in \p list.
 * @param[in] list The @ref dptX_list "list" of which the last dataStruct is needed.
 * @returns The dataStruct of the last node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */

/// @details Gets the dpt1_node::dataStruct of the last added dpt1_node in \p list.
struct dpt1 dpt1LastData(const dpt1_list* list)
{
	const struct dpt1 dat = { 0, 0, 0 };
	const struct dpt1_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt7_node::dataStruct of the last added dpt7_node in \p list.
struct dpt7 dpt7LastData(const dpt7_list* list)
{
	const struct dpt7 dat = { 0, 0, 0 };
	const struct dpt7_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt10_node::dataStruct of the last added dpt10_node in \p list.
struct dpt10 dpt10LastData(const dpt10_list* list)
{
	const struct dpt10 dat = { 0, 0, 0 };
	const struct dpt10_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt12_node::dataStruct of the last added dpt12_node in \p list.
struct dpt12 dpt12LastData(const dpt12_list* list)
{
	const struct dpt12 dat = { 0, 0, 0 };
	const struct dpt12_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt215_node::dataStruct of the last added dpt215_node in \p list.
struct dpt215 dpt215LastData(const dpt215_list* list)
{
	const struct dpt215 dat = { 0, 0, 0 };
	const struct dpt215_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt212_node::dataStruct of the last added dpt212_node in \p list.
struct dpt212 dpt212LastData(const dpt212_list* list)
{
	const struct dpt212 dat = { 0, 0, 0 };
	const struct dpt212_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt19_node::dataStruct of the last added dpt19_node in \p list.
struct dpt19 dpt19LastData(const dpt19_list* list)
{
	const struct dpt19 dat = { 0, 0, 0 };
	const struct dpt19_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}

/// @details Gets the dpt16_node::dataStruct of the last added dpt16_node in \p list.
struct dpt16 dpt16LastData(const dpt16_list* list)
{
	const struct dpt16 dat = { 0, 0, 0 };
	const struct dpt16_node* head = *list;

	if (NULL == head) {
		return dat;
	}

	return head->dataStruct;
}
///@}
///@}

// - FirstData ----------------------------------------------------------------
/**
 * @defgroup dptXFirstData First data
 * @brief Gets the @ref dataStruct of the first added @ref dptX_node "node".
 * @details The dataStruct of the first added node in \p list will be returned.
 * @param[in] list The @ref dptX_list "list" of which the first dataStruct is needed.
 * @returns The dataStruct of the first node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */
/**
 * @name dptXFirstData
 * @brief Gets the @ref dataStruct of the first added @ref dptX_node "node".
 * @param[in] list The @ref dptX_list "list" of which the first dataStruct is needed.
 * @returns The dataStruct of the first node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */

/// @details Gets the dpt1_node::dataStruct of the first added dpt1_node in \p list.
struct dpt1 dpt1FirstData(const dpt1_list* list)
{
	const struct dpt1 dat = { 0, 0, 0 };
	struct dpt1_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt7_node::dataStruct of the first added dpt7_node in \p list.
struct dpt7 dpt7FirstData(const dpt7_list* list)
{
	const struct dpt7 dat = { 0, 0, 0 };
	struct dpt7_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt10_node::dataStruct of the first added dpt10_node in \p list.
struct dpt10 dpt10FirstData(const dpt10_list* list)
{
	const struct dpt10 dat = { 0, 0, 0 };
	struct dpt10_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt12_node::dataStruct of the first added dpt12_node in \p list.
struct dpt12 dpt12FirstData(const dpt12_list* list)
{
	const struct dpt12 dat = { 0, 0, 0 };
	struct dpt12_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt215_node::dataStruct of the first added dpt215_node in \p list.
struct dpt215 dpt215FirstData(const dpt215_list* list)
{
	const struct dpt215 dat = { 0, 0, 0 };
	struct dpt215_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt212_node::dataStruct of the first added dpt212_node in \p list.
struct dpt212 dpt212FirstData(const dpt212_list* list)
{
	const struct dpt212 dat = { 0, 0, 0 };
	struct dpt212_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt19_node::dataStruct of the first added dpt19_node in \p list.
struct dpt19 dpt19FirstData(const dpt19_list* list)
{
	const struct dpt19 dat = { 0, 0, 0 };
	struct dpt19_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}

/// @details Gets the dpt16_node::dataStruct of the first added dpt16_node in \p list.
struct dpt16 dpt16FirstData(const dpt16_list* list)
{
	const struct dpt16 dat = { 0, 0, 0 };
	struct dpt16_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return dat;
	}

	// List contains multiple nodes
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr->dataStruct;
}
///@}
///@}

// - FirstNode ----------------------------------------------------------------
/**
 * @defgroup dptXFirstNode First node
 * @brief Gets the first added @ref dptX_node "node" in \p list.
 * @details The first added node will be returned.
 * @param[in] list The @ref dptX_list "list" of which the first node is needed.
 * @returns The first node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @warning If this node is freed (by either @ref dptXPopFirst "popping the node",
 * @ref dptXEmptyList "emptying the list" or @ref dptXFreeList "freeing the list")
 * the node will also be freed and hold garbage.
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */
/**
 * @name dptXFirstNode
 * @brief Gets the first added @ref dptX_node "node" in \p list.
 * @param[in] list The @ref dptX_list "list" of which the first node is needed.
 * @returns The first node in \p list.
 * @retval {0, 0, 0} if \p list is empty
 * @warning If this node is freed (by either @ref dptXPopFirst "popping the node",
 * @ref dptXEmptyList "emptying the list" or @ref dptXFreeList "freeing the list")
 * the node will also be freed and hold garbage.
 * @pre \p list must be created first.
 * @note This function will not remove anything from \p list.
 * @{
 */

/// @details Gets the first added dpt1_node in \p list.
struct dpt1_node* dpt1FirstNode(const dpt1_list* list)
{
	struct dpt1_node* curr = *list;
	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt7_node in \p list.
struct dpt7_node* dpt7FirstNode(const dpt7_list* list)
{
	struct dpt7_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt10_node in \p list.
struct dpt10_node* dpt10FirstNode(const dpt10_list* list)
{
	struct dpt10_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt12_node in \p list.
struct dpt12_node* dpt12FirstNode(const dpt12_list* list)
{
	struct dpt12_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt215_node in \p list.
struct dpt215_node* dpt215FirstNode(const dpt215_list* list)
{
	struct dpt215_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt212_node in \p list.
struct dpt212_node* dpt212FirstNode(const dpt212_list* list)
{
	struct dpt212_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt19_node in \p list.
struct dpt19_node* dpt19FirstNode(const dpt19_list* list)
{
	struct dpt19_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}

/// @details Gets the first added dpt16_node in \p list.
struct dpt16_node* dpt16FirstNode(const dpt16_list* list)
{
	struct dpt16_node* curr = *list;

	// List is empty
	if (NULL == curr) {
		return NULL;
	}

	// List contains at least one node
	while (NULL != curr->next) {
		curr = curr->next;
	}

	return curr;
}
///@}
///@}
