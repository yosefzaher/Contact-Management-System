#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "../low_level_layer/Linked_List.h"

/**
 * @brief  : Load all contacts from the CSV file into the linked list.
 * @param  : (ListHead) Pointer to the head of the linked list.
 * @param  : (filename) Name of the CSV file to load data from.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Load_Contacts_From_File(Contact_Info_t **ListHead, const char *filename);

/**
 * @brief  : Save all contacts from the linked list into the CSV file.
 * @param  : (ListHead) Pointer to the head of the linked list.
 * @param  : (filename) Name of the CSV file to save data to.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Save_Contacts_To_File(Contact_Info_t *ListHead, const char *filename);

#endif // _DATA_BASE_H_

