#include "Linked_List.h"


/**
 * @brief  : Add a new contact at the end of the list.
 * @param  : (ListHead) Pointer to the head of the list.
 * @param  : (Name) Name of the new contact.
 * @param  : (Email) Email of the new contact.
 * @param  : (Phone_Number) Phone number of the new contact.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Insert_At_End(Contact_Info_t **ListHead, int8_t *Name, int8_t *Email, int8_t *Phone_Number){

    Contact_Info_t *newContact = (Contact_Info_t *) malloc(sizeof(Contact_Info_t)) ;

    if(!(newContact))
    {
        return STD_ERROR;
    }

    strcpy(newContact->Name, Name) ;
    strcpy(newContact->Email, Email) ;
    strcpy(newContact->Phone_Number, Phone_Number) ;
    newContact->Next_Contact = NULL ;

    if(*ListHead == NULL)
    {
        *ListHead = newContact ;
    }
    else
    {
        Contact_Info_t *temp = *ListHead ;
        while(temp->Next_Contact != NULL)
        {
            temp = temp->Next_Contact ;
        }
        temp->Next_Contact = newContact ;
    }

    return STD_OK;
}

/**
 * @brief  : Delete a contact by its index in the list.
 * @param  : (ListHead) Pointer to the head of the list.
 * @param  : (Index) Index of the contact to be deleted.
 * @return : (STD_OK) if the operation is successful ,(STD_ERROR) if the operation fault
 *           ,(STD_INDEX_OUT_OF_BOUNDARY) if Index out of the boundary.
 */
Std_ReturnType Delete_Index(Contact_Info_t **ListHead, int8_t Index){

    if(*ListHead == NULL)
    {
        return STD_ERROR ;
    }

    Contact_Info_t *temp = *ListHead ;

    Contact_Info_t *prev = NULL ;

    for(int i = 0 ; i < Index ; i++)
    {
        prev = temp ;
        temp = temp->Next_Contact ;
    }

    if(prev == NULL)
    {
        *ListHead = temp->Next_Contact ;
    }
    else
    {
        prev->Next_Contact = temp->Next_Contact ;
    }

    free(temp) ;

    return STD_OK;
}

/**
 * @brief  : Search for a contact by phone number.
 * @param  : (ListHead) Head of the list.
 * @param  : (Phone_Number) Phone number to search for.
 * @param  :  (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the PhoneNumber is found, (STD_NOT_FOUND) if not found
 */
Std_ReturnType Search_For_PhoneNumber(Contact_Info_t *ListHead, int8_t *Phone_Number, int8_t *Returned_Index){

    Contact_Info_t *temp = ListHead ;
    int8_t index = 0 ;

    while(temp)
    {
        if(strcmp(temp->Phone_Number ,Phone_Number) == 0)
        {
            *Returned_Index = index ;
            return STD_OK ;
        }
        temp = temp->Next_Contact ;
        index++ ;
    }

    *Returned_Index = -1 ;

    return STD_NOT_FOUND ;
}

/**
 * @brief  : Search for a contact by email.
 * @param  : (ListHead) Head of the list.
 * @param  : (Email) Email to search for.
 * @param  : (Returned_Index) Pointer to store the index of the found contact.
 * @return : (STD_OK) if the Email is found, (STD_NOT_FOUND) if not found .
 */
Std_ReturnType Search_For_Email(Contact_Info_t *ListHead, int8_t *Email, int8_t *Returned_Index)
{
    Contact_Info_t *temp = ListHead ;
    int8_t index = 0 ;

    while(temp)
    {
        if(strcmp(temp->Email, Email) == 0)
        {
            *Returned_Index = index ;
            return STD_OK ;
        }
        temp = temp->Next_Contact ;
        index++ ;
    }

    *Returned_Index = -1 ;

    return STD_NOT_FOUND ;
}

/**
 * @brief : Update the email of a specific contact.
 * @param : (ListHead) Head of the list.
 * @param : (Index) Index of the contact whose email is to be updated.
 * @param : (New_Email) New email.
 * @return : (STD_OK) if the operation is successful, (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Update_Email(Contact_Info_t *ListHead, int8_t Index, int8_t *New_Email){

    Contact_Info_t *temp = ListHead ;

    for(int i = 0 ; i < Index ; i++)
    {
        if(temp == NULL)
        {
            return STD_NOT_FOUND ;
        }
        temp = temp->Next_Contact ;
    }

    strcpy(temp->Email,New_Email) ;

    return STD_OK;
}

/**
 * @brief  : Update the phone number of a specific contact.
 * @param  : (ListHead) Head of the list.
 * @param  : (Index) Index of the contact whose phone number is to be updated.
 * @param  : (New_Phone_Number) New phone number.
 * @return : (STD_OK) if the operation is successful, (STD_NOT_FOUND) if Email not found.
 */
Std_ReturnType Update_PhoneNumber(Contact_Info_t *ListHead, int8_t Index, int8_t *New_Phone_Number){

    Contact_Info_t *temp = ListHead ;

    for(int i = 0 ; i < Index ; i++)
    {
        if(temp == NULL)
        {
            return STD_NOT_FOUND ;
        }
        temp = temp->Next_Contact ;
    }

    strcpy(temp->Phone_Number ,New_Phone_Number) ;

    return STD_OK;
}

/**
 * @brief  : Get the number of contacts in the list.
 * @param  : (ListHead) Head of the list.
 * @param  : (Number_of_Contacts) Pointer to store the number of contacts.
 * @return : (STD_OK) if the operation is successful.
 */
Std_ReturnType Get_List_Length(Contact_Info_t *ListHead ,int8_t *Number_of_Contacts)
{
    Contact_Info_t *temp = ListHead ;
    int8_t count = 0 ;

    if(ListHead == NULL)
    {
        return count;
    }

    while(temp != NULL)
    {
        count++ ;
        temp = temp->Next_Contact ;
    }
    *Number_of_Contacts = count ;

    return STD_OK ;
}

/**
 * @brief  : Display all contacts in the list.
 * @param  :(ListHead) Head of the list.
 * @return : (void)
 **/
void display_All_Linked_List(Contact_Info_t *ListHead)
{
    uint8_t Counter = 1 ;
    Contact_Info_t *temp = ListHead;

    if (!temp)
    {
        printf("Contact list is empty.\n\n") ;
        return ;
    }

    printf("=====================================================\n") ;
    while(temp)
    {
        printf("=Contact[%d] :-\n",(Counter)) ;
        printf("\tName: %s\n\tPhone: %s\n\tEmail: %s\n", temp->Name, temp->Phone_Number, temp->Email) ;
        printf("=====================================================\n") ;
        temp = temp->Next_Contact ;
        Counter++ ;
    }
    printf("\n\n") ;
}
