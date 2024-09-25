#ifndef _CHECK_DATA_H_
#define _CHECK_DATA_H_

#include "../../low_level_layer/Linked_List.h"

/**
 * @brief  : Check if the name contains spaces at the beginning or end.
 * @param  : (name) Name to be checked.
 * @return : (STD_OK) if no spaces at the beginning or end, otherwise (STD_ERROR).
 */
Std_ReturnType static Check_Spaces_error(char *name);

/**
 * @brief  : Check if the string contains any spaces.
 * @param  : (str) String to be checked.
 * @return : (STD_OK) if no spaces, otherwise (STD_ERROR).
 */
Std_ReturnType static Contains_Space(const char *str);

/**
 * @brief  : Prompt the user to enter their name again.
 * @param  : (name) Buffer to store the name.
 */
void static Name_again(char *name);

/**
 * @brief  : Prompt the user to enter their email again.
 * @param  : (Email) Buffer to store the email.
 */
void static Email_again(char *Email);

/**
 * @brief  : Prompt the user to enter their phone number again.
 * @param  : (PhoneNumber) Buffer to store the phone number.
 */
void static PhoneNumber_again(char *PhoneNumber);

/**
 * @brief  : Check the validity of the name.
 * @param  : (name) Name to be checked.
 * @return : (STD_OK) if the name is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_name(char *name);

/**
 * @brief  : Check the validity of the phone number.
 * @param  : (PhoneNumber) Phone number to be checked.
 * @return : (STD_OK) if the phone number is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_PhoneNumber(char *PhoneNumber);

/**
 * @brief  : Check the validity of the email address.
 * @param  : (Email) Email address to be checked.
 * @return : (STD_OK) if the email is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_Email(char *Email);


/**
 * @brief  Check if an email is already in the linked list.
 * @param  Email: The email address to be checked.
 * @return STD_OK if the email is found in the list, otherwise STD_NOT_FOUND.
 */
Std_ReturnType Check_Email_In_List(const char *Email) ;

/**
 * @brief  Check if a phone number is already in the linked list.
 * @param  PhoneNumber: The phone number to be checked.
 * @return STD_OK if the phone number is found in the list, otherwise STD_NOT_FOUND.
 */
Std_ReturnType Check_PhoneNumber_In_List(const char *PhoneNumber) ;

#endif // CHECK_FUNCTIONS_H






