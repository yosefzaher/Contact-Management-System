#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


#include "Std_Libraries.h"
#include "DataType.h"


// Declare the Contact Information structure
typedef struct Contact
{
    struct Contact *Next_Contact;
    int8_t Name[100];
    int8_t Email[50];
    int8_t Phone_Number[12];
}Contact_Info_t;


// Declare the Standard Status Return Type
typedef enum
{
    STD_ERROR = 0 ,
    STD_OK ,
    STD_NOT_FOUND ,
}Std_ReturnType;


// Declarations Of Low Level Functions

/**
 * @brief  : Add a new contact at the end of the list.
 * @param  : (ListHead) Pointer to the head of the list.
 * @param  : (Name) Name of the new contact.
 * @param  : (Email) Email of the new contact.
 * @param  : (Phone_Number) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Insert_At_End(Contact_Info_t **ListHead, int8_t *Name, int8_t *Email, int8_t *Phone_Number);

/**
 * @brief  : Delete a contact by its index in the list.
 * @param  : (ListHead) Pointer to the head of the list.
 * @param  : (Index) Index of the contact to be deleted.
 * @return : (STD_OK) if the operation is successful ,(STD_ERROR) if the operation fault .
 */
Std_ReturnType Delete_Index(Contact_Info_t **ListHead, int8_t Index);

/**
 * @brief  : Search for a contact by phone number.
 * @param  : (ListHead) Head of the list.
 * @param  : (Phone_Number) Phone number to search for.
 * @param  :  (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the PhoneNumber is found, (STD_NOT_FOUND) if not found
 */
Std_ReturnType Search_For_PhoneNumber(Contact_Info_t *ListHead, int8_t *Phone_Number, int8_t *Returned_Index);

/**
 * @brief  : Search for a contact by email.
 * @param  : (ListHead) Head of the list.
 * @param  : (Email) Email to search for.
 * @param  : (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the Email is found, (STD_NOT_FOUND) if not found
 */
Std_ReturnType Search_For_Email(Contact_Info_t *ListHead, int8_t *Email, int8_t *Returned_Index);

/**
 * @brief : Update the email of a specific contact.
 * @param : (ListHead) Head of the list.
 * @param : (Index) Index of the contact whose email is to be updated.
 * @param : (New_Email) New email.
 * @return : (STD_OK) if the operation is successful, (STD_ERROR) if the operation fault.
 */
Std_ReturnType Update_Email(Contact_Info_t *ListHead, int8_t Index, int8_t *New_Email);

/**
 * @brief  : Update the phone number of a specific contact.
 * @param  : (ListHead) Head of the list.
 * @param  : (Index) Index of the contact whose phone number is to be updated.
 * @param  : (New_Phone_Number) New phone number.
 * @return : (STD_OK) if the operation is successful, (STD_ERROR) if the operation fault , (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Update_PhoneNumber(Contact_Info_t *ListHead, int8_t Index, int8_t *New_Phone_Number);

/**
 * @brief  : Get the number of contacts in the list.
 * @param  : (ListHead) Head of the list.
 * @param  : (Number_of_Contacts) Pointer to store the number of contacts.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR) .
 */
Std_ReturnType Get_List_Length(Contact_Info_t *ListHead,int8_t * Number_of_Contacts);

/**
 * @brief  : Display all contacts in the list.
 * @param  :(ListHead) Head of the list.
 * @return : (void)
 **/
void display_All_Linked_List(Contact_Info_t *ListHead);

//////////////////////////////////////



#endif // _LINKED_LIST_H_
