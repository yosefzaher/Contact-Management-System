#ifndef _CONTACT_INFO_H_
#define _CONTACT_INFO_H_


#include "../../low_level_layer/Linked_List.h"


#define MAX_CONTACTS 5

#define PHONE_NUMBER_EXIST 1
#define PHONE_NUMBER_NOT_EXIST 0
#define EMAIL_EXIST 1
#define EMAIL_NOT_EXIST 0


/**
 * @brief  : Load all contacts from the CSV file into the linked list.
 * @param  : None
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 *
 * This function reads contact data from the specified CSV file (`DataBase_File`)
 * and populates the global linked list (`ListHead`) with the loaded contacts.
 * If the loading operation fails, an error message is printed; otherwise,
 * a success message is displayed.
 */
Std_ReturnType Load_Data(void) ;

/**
 * @brief  : Save all contacts from the linked list into the CSV file.
 * @param  : None
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 *
 * This function writes the contact data from the global linked list (`ListHead`)
 * to the specified CSV file (`DataBase_File`). If the saving operation fails,
 * an error message is printed; otherwise, a success message is displayed.
 */
Std_ReturnType Upload_Data(void) ;

/**
 * @brief  : Add a new contact at the end of the list.
 * @param  : (Name) Name of the new contact.
 * @param  : (Email) Email of the new contact.
 * @param  : (PhoneNumber) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Contact_Add(char* Name, char* Email, char* PhoneNumber);

/**
 * @brief  : Delete a contact by its index in the list.
 * @param  : (PhoneNumber) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful ,(STD_ERROR) if the operation fault .
 */
Std_ReturnType Contact_Delete(char* PhoneNumber);

/**
 * @brief  : Display all contacts in the list.
 * @param  : (void)
 * @return : (void)
 **/
Std_ReturnType Contact_Display_All(void);

/**
 * @brief : checks if the contact exists then update the email of a specific contact.
 * @param  : (Email) Email of the  contact.
 * @param : (New_Email) New email.
 * @return : (STD_OK) if the operation is successful, (STD_ERROR) if the operation fault , (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Contact_Update_Email(char* New_Email ,int8_t Index) ;

/**
 * @brief : checks if the contact exists then update the phone number of a specific contact.
 * @param  : (PhoneNumber) Phone number of the  contact.
 * @param  : (New_PhoneNumber) New phone number.
 * @return : (STD_OK) if the operation is successful, (STD_ERROR) if the operation fault , (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Contact_Update_Phone_Number(char* New_PhoneNumber ,int8_t Index) ;

/**
 * @brief  : Checks if the contact exists then searches for a contact by phone number.
 * @param  : (Phone_Number) Phone number to search for.
 * @param  :  (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the PhoneNumber is found, (STD_NOT_FOUND) if not found, (STD_ERROR) if the operation fault.
 */
Std_ReturnType  Contact_Search_Phone_Number(char* PhoneNumber, char* Returned_Index);

/**
 * @brief  : Checks if the contact exists then searches for a contact by email.
 * @param  : (Email) Email to search for.
 * @param  : (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the Email is found, (STD_NOT_FOUND) if not found, (STD_ERROR) if the operation fault.
 */
Std_ReturnType Contact_Search_Email(char* Email, char* Returned_Index);














#endif // _CONTACT_INFO_H_
