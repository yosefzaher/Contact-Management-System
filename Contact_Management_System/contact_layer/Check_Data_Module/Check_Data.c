#include "Check_Data.h"

extern Contact_Info_t *ListHead ;


/**
 * @brief  : Check if the name contains spaces at the beginning or end.
 * @param  : (name) Name to be checked.
 * @return : (STD_OK) if no spaces at the beginning or end, otherwise (STD_ERROR).
 */
Std_ReturnType static Check_Spaces_error(char *name)
{
    int length = strlen(name);

    if (name[0] == ' ' || name[length - 1] == ' ')
        return STD_ERROR;

    return STD_OK;
}

/**
 * @brief  : Check if the string contains any spaces.
 * @param  : (str) String to be checked.
 * @return : (STD_OK) if no spaces, otherwise (STD_ERROR).
 */
Std_ReturnType static Contains_Space(const char *str)
{
    while (*str)
    {
        if (*str == ' ')
            return STD_ERROR;
        str++;
    }
    return STD_OK;
}

/**
 * @brief  : Prompt the user to enter their name again.
 * @param  : (name) Buffer to store the name.
 */
void static Name_again(char *name)
{
    size_t size = 101;
    fflush(stdin) ;
    printf("Enter your name again: ");
    if (fgets(name, size, stdin) != NULL)
    {
        // Remove the newline character if it's present
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
            name[len - 1] = '\0';
    }
    printf("\n\n") ;
}

/**
 * @brief  : Prompt the user to enter their email again.
 * @param  : (Email) Buffer to store the email.
 */
void static Email_again(char *Email)
{
    size_t size = 100;
    fflush(stdin) ;
    printf("Enter your email again: ");
    if (fgets(Email, size, stdin) != NULL)
    {
        // Remove the newline character if it's present
        size_t len = strlen(Email);
        if (len > 0 && Email[len - 1] == '\n')
            Email[len - 1] = '\0';
    }

}

/**
 * @brief  : Prompt the user to enter their phone number again.
 * @param  : (PhoneNumber) Buffer to store the phone number.
 */
void static PhoneNumber_again(char *PhoneNumber)
{
    size_t size = 12;
    fflush(stdin) ;
    printf("Enter your phone number again: ");
    if (fgets(PhoneNumber, size, stdin) != NULL)
    {
        // Remove the newline character if it's present
        size_t len = strlen(PhoneNumber);
        if (len > 0 && PhoneNumber[len - 1] == '\n')
            PhoneNumber[len - 1] = '\0';
    }
    printf("\n\n") ;
}

/**
 * @brief  : Check the validity of the name.
 * @param  : (name) Name to be checked.
 * @return : (STD_OK) if the name is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_name(char *name)
{
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    while (1)
    {
        if (Check_Spaces_error(name) == STD_ERROR)
        {
            printf("There shouldn't be any spaces at the beginning or the end of the name\n\n");
            Name_again(name);
            continue;
        }

        int length = strlen(name);

        if (length == 0 || length > 100)
        {
            printf("Your name shouldn't exceed 100 characters\n\n");
            Name_again(name);
            continue;
        }

        int valid = 1;
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(name[i]))
            {
                if (name[i] == ' ' && isalpha(name[i + 1]))
                {
                    i++;
                    continue;
                }
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("Name contains invalid characters\n\n");
            Name_again(name);
            continue;
        }

        printf("Name is valid\n\n");
        return STD_OK;
    }
}

/**
 * @brief  : Check the validity of the phone number.
 * @param  : (PhoneNumber) Phone number to be checked.
 * @return : (STD_OK) if the phone number is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_PhoneNumber(char *PhoneNumber)
{
    size_t len = strlen(PhoneNumber);
    if (len > 0 && PhoneNumber[len - 1] == '\n')
        PhoneNumber[len - 1] = '\0';

    while (1)
    {
        int length = strlen(PhoneNumber);

        if (length != 11)
        {
            printf("Phone number should be exactly 11 characters long\n\n");
            PhoneNumber_again(PhoneNumber);
            continue;
        }

        if (strncmp(PhoneNumber, "010", 3) == 0 || strncmp(PhoneNumber, "011", 3) == 0 ||
            strncmp(PhoneNumber, "015", 3) == 0 || strncmp(PhoneNumber, "012", 3) == 0)
        {
            int valid = 1;
            for (int i = 3; i < length; i++)
            {
                if (!isdigit(PhoneNumber[i]))
                {
                    valid = 0;
                    break;
                }
            }

            if (valid)
            {
                printf("Phone number is valid\n\n");
                return STD_OK;
            }
            else
            {
                printf("Phone number contains invalid characters\n\n");
                PhoneNumber_again(PhoneNumber);
                continue;
            }
        }
        else
        {
            printf("Phone number should start with '010', '011', '012', or '015'\n\n");
            PhoneNumber_again(PhoneNumber);
            continue;
        }
    }
}

/**
 * @brief  : Check the validity of the email address.
 * @param  : (Email) Email address to be checked.
 * @return : (STD_OK) if the email is valid, otherwise (STD_ERROR).
 */
Std_ReturnType Check_Email(char *Email)
{
    size_t len = strlen(Email);
    if (len > 0 && Email[len - 1] == '\n')
        Email[len - 1] = '\0';

    const char *suffix = "@gmail.com";
    int suffix_length = strlen(suffix);

    while (1)
    {
        int length = strlen(Email);

        if (length < suffix_length)
        {
            printf("Email is too short to be a valid Gmail address\n\n");
            Email_again(Email);
            continue;
        }

        if (Contains_Space(Email) == STD_ERROR)
        {
            printf("Email should not contain spaces\n\n");
            Email_again(Email);
            continue;
        }

        if (strcmp(Email + length - suffix_length, suffix) == 0)
        {
            printf("Email is valid\n\n");
            return STD_OK;
        }
        else
        {
            printf("Email should end with '%s'\n\n", suffix);
            Email_again(Email);
        }
    }
}

/**
 * @brief  Check if an email is already in the linked list.
 * @param  Email: The email address to be checked.
 * @return STD_OK if the email is found in the list, otherwise STD_NOT_FOUND.
 */
Std_ReturnType Check_Email_In_List(const char *Email)
{
    Std_ReturnType ret = STD_OK;
    Contact_Info_t *Temp = ListHead;

    while (Temp != NULL)
    {
        if (!(strcmp(Temp->Email, Email)))
        {
            ret = STD_ERROR;
            printf("Email is Already Exist In Data Base, This is Invalid! :( \n\n") ;
            Email_again(Email) ;
            return ret ;
        }
        Temp = Temp->Next_Contact;
    }
    ret = STD_OK ;
    return ret;
}

/**
 * @brief  Check if a phone number is already in the linked list.
 * @param  PhoneNumber: The phone number to be checked.
 * @return STD_OK if the phone number is found in the list, otherwise STD_NOT_FOUND.
 */
Std_ReturnType Check_PhoneNumber_In_List(const char *PhoneNumber)
{
    Std_ReturnType ret = STD_OK;
    Contact_Info_t *Temp = ListHead;

    while (Temp != NULL)
    {
        if (!(strcmp(Temp->Phone_Number, PhoneNumber)))
        {
            ret = STD_ERROR;
            printf("Phone Number is Already Exist In Data Base, This is Invalid! :( \n\n") ;
            PhoneNumber_again(PhoneNumber) ;
            return ret ;
        }
        Temp = Temp->Next_Contact;
    }
    ret = STD_OK ;
    return ret;
}


