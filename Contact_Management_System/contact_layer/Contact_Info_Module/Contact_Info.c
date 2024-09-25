#include "Contact_Info.h"

Contact_Info_t *ListHead = NULL ;
char *DataBase_File = "contacts.csv" ;

/**
 * @brief Retrieve the length of the contact list.
 *
 * This function calculates and returns the length of the contact list by calling
 * the `Get_List_Length` function with the head of the list. It is useful to determine
 * how many contacts are currently stored in the system.
 *
 * @return int8_t
 *     The number of contacts in the list.
 *     Returns 0 if the list is empty or if there was an error retrieving the length.
 */
int8_t Contact_List_Length(void)
{
    int8_t Len = 0;

    Get_List_Length(ListHead, &Len);

    return Len;

}

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
Std_ReturnType Load_Data(void)
{
    Std_ReturnType ret = STD_OK ;

    ret = Load_Contacts_From_File(&ListHead ,DataBase_File) ;
    if (ret != STD_OK) {
        printf("Failed to load contacts from file.\n");
    }
    else
    {
        printf("=>Data Loaded Sccessflly :) \n\n") ;
    }
    return ret ;
}

/**
 * @brief  : Save all contacts from the linked list into the CSV file.
 * @param  : None
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 *
 * This function writes the contact data from the global linked list (`ListHead`)
 * to the specified CSV file (`DataBase_File`). If the saving operation fails,
 * an error message is printed; otherwise, a success message is displayed.
 */
Std_ReturnType Upload_Data(void)
{
    Std_ReturnType ret = STD_OK ;

    ret = Save_Contacts_To_File(&ListHead ,DataBase_File) ;
    if (ret != STD_OK) {
        printf("Failed to Upload contacts from file.\n");
    }
    else
    {
        printf("Data Uploaded Sccessflly. \n\n") ;
    }
    return ret ;
}

/**
 * @brief  : Add a new contact at the end of the list.
 * @param  : (Name) Name of the new contact.
 * @param  : (Email) Email of the new contact.
 * @param  : (PhoneNumber) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Contact_Add(char* Name, char* Email, char* PhoneNumber)
{
    Std_ReturnType ret = STD_OK ;

    int8_t Length = 0 ;

    int8_t Phone_Number_Index = 0 ;
    int8_t Email_Index = 0 ;

    int8_t PhoneNumber_Check = 0 ;
    int8_t Email_Check = 0 ;

    ret = Get_List_Length(ListHead ,&Length) ;

    if(Length == MAX_CONTACTS)
    {
        printf("Data Base Is Full ,Can't Add Any Contacts. \n\n") ;
        ret = STD_ERROR ;
    }
    else
    {
        ret = Insert_At_End(&ListHead ,Name ,Email ,PhoneNumber) ;
        if(ret == STD_OK)
        {
            printf("Contact Added Successfully :) \n\n") ;
        }
        else
        {
            printf("Add Contact Fault !! \n\n") ;
        }
    }
    return ret ;
}


/**
 * @brief  : Delete a contact by its index in the list.
 * @param  : (PhoneNumber) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful ,(STD_ERROR) if the operation fault .
 */
Std_ReturnType Contact_Delete(char* PhoneNumber)
{
    Std_ReturnType ret = STD_OK ;

    int8_t Length = 0 ;
    int8_t Index = 0 ;

    ret = Get_List_Length(ListHead ,&Length) ;
    if(ret = STD_OK)
    {
        if(Length == 0)
        {
            printf("Contact List is Empty ,Can't Delete Contact.\n\n") ;
        }
        else
        {
            ret = Search_For_PhoneNumber(ListHead ,PhoneNumber ,&Index) ;
            if(ret == STD_OK)
            {
                ret = Delete_Index(&ListHead ,Index) ;
                if(ret == STD_OK)
                {
                    printf("Contact Deleted Successfully :) \n\n") ;
                }
                else
                {
                    printf("Contact Deleting Fault. \n\n") ;
                }
            }
            else
            {
                printf("Contact Not Found. \n\n") ;
            }
        }
    }
    else
    {
        ret = STD_ERROR ;
    }
    return ret ;
}


/**
 * @brief  : Display all contacts in the list.
 * @param  : (void)
 * @return : (void)
 **/
Std_ReturnType Contact_Display_All(void)
{
    Std_ReturnType ret = STD_OK ;

    display_All_Linked_List(ListHead) ;

    return ret ;
}


/**
 * @brief : checks if the contact exists then update the email of a specific contact.
 * @param  : (Email) Email of the  contact.
 * @param : (New_Email) New email.
 * @return : (STD_OK) if the operation is successful, (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Contact_Update_Email(char* New_Email ,int8_t Index)
{
    Std_ReturnType ret = STD_OK ;

    ret = Update_Email(ListHead ,Index ,New_Email) ;

    if(ret == STD_OK)
    {
        printf("Email Updated Successfully :) \n\n") ;
    }
    else
    {
        printf("Updating Email Fault. \n\n") ;
    }
    return ret ;
}


/**
 * @brief : checks if the contact exists then update the phone number of a specific contact.
 * @param  : (PhoneNumber) Phone number of the  contact.
 * @param  : (New_PhoneNumber) New phone number.
 * @return : (STD_OK) if the operation is successful, (STD_ERROR) if the operation fault , (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Contact_Update_Phone_Number(char* New_PhoneNumber ,int8_t Index)
{
    Std_ReturnType ret = STD_OK ;

    ret = Update_PhoneNumber(ListHead ,Index ,New_PhoneNumber) ;

    if(ret == STD_OK)
    {
        printf("Phone Number Updated Successfully :) \n\n") ;
    }
    else
    {
        printf("Updating Phone Number Fault. \n\n") ;
    }
    return ret ;

}


/**
 * @brief  : Checks if the contact exists then searches for a contact by phone number.
 * @param  : (Phone_Number) Phone number to search for.
 * @param  :  (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the PhoneNumber is found, (STD_NOT_FOUND) if not found, (STD_ERROR) if the operation fault.
 */
Std_ReturnType  Contact_Search_Phone_Number(char* PhoneNumber, char* Returned_Index)
{
    Std_ReturnType ret = STD_OK ;
    int8_t length = 0 ;

    ret = Get_List_Length(ListHead ,&length) ;
    if(!length)
    {
        printf("Contact List is Empty .\n\n") ;
    }

    ret = Search_For_PhoneNumber(ListHead ,PhoneNumber ,Returned_Index) ;
    if(ret == STD_NOT_FOUND)
    {
        printf("Contact Not Found. \n\n") ;
    }
    else
    {
        ret = STD_OK ;
    }

    return ret ;
}


/**
 * @brief  : Checks if the contact exists then searches for a contact by email.
 * @param  : (Email) Email to search for.
 * @param  : (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the Email is found, (STD_NOT_FOUND) if not found, (STD_ERROR) if the operation fault.
 */
Std_ReturnType Contact_Search_Email(char* Email, char* Returned_Index)
{
    Std_ReturnType ret = STD_OK ;
    int8_t length = 0 ;

    ret = Get_List_Length(ListHead ,&length) ;
    if(!length)
    {
        printf("Contact List is Empty .\n\n") ;
    }


    ret = Search_For_Email(ListHead ,Email ,Returned_Index) ;
    if(ret == STD_NOT_FOUND)
    {
        printf("Contact Not Found. \n\n") ;
    }
    else
    {
        ret = STD_OK ;
    }

    return ret ;
}



















