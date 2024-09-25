#include "main.h"

char input[100];

char Name[101];
char Email[51];
char Phone_Number[12];

Std_ReturnType ret = STD_OK;
int8_t Index = 0;
int8_t Option = 0;
int8_t Len = 0 ;

char Count = 0;
char *Welcome_Statement = "Hello in Contact Management System :)\n";

int main()
{
    Start_Program(Welcome_Statement, Count);
    printf("\n\n");

    printf("-Downloading Data, Please Wait a Few Seconds");
    for (int i = 0; i < 16; i++)
    {
        printf(".");
        Sleep(150);
    }
    printf("\n\n");
    ret = Load_Data();

    while(1)
    {

        printf("What Do You Want To Do ??\n");
        for (int i = 0; i < 40; i++)
        {
            printf("-");
        }
        printf("\n\n");
        Sleep(100);
        printf("\t1 => Add New Contact To The System.\n\n");
        Sleep(100);
        printf("\t2 => Delete Contact From The System.\n\n");
        Sleep(100);
        printf("\t3 => Update Phone Number In The System.\n\n");
        Sleep(100);
        printf("\t4 => Update Email In The System.\n\n");
        Sleep(100);
        printf("\t5 => Search For A Phone Number In The System.\n\n");
        Sleep(100);
        printf("\t6 => Search For An Email In The System.\n\n");
        Sleep(100);
        printf("\t7 => Display All The Contacts In The System.\n\n");
        Sleep(100);
        printf("\t8 => Quit The Program.\n\n");
        Sleep(100);
        for (int i = 0; i < 40; i++)
        {
            printf("-");
        }
        printf("\n\n");

        do
        {
            fflush(stdin) ;
            printf("Enter The Option You Want (1-8): ");
            if (fgets(input, sizeof(input), stdin) != NULL)
            {
                // Remove newline character from input if present
                input[strcspn(input, "\n")] = '\0';

                // Check if input is a single digit
                if (strlen(input) == 1 && isdigit(input[0]))
                {
                    Option = input[0] - '0'; // Convert char to int

                    if (Option >= 1 && Option <= 8)
                    {
                        break; // Valid option, exit loop
                    }
                }
            }

            printf("Invalid option. Please enter a number between 1 and 8.\n\n");
        } while (1);


        switch (Option)
        {
            case 1:
                Len = Contact_List_Length() ;
                if(Len < MAX_CONTACTS)
                {
                    do
                    {

                        printf("Enter The Name: ");
                        if (fgets(Name, sizeof(Name), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Name[strcspn(Name, "\n")] = '\0';
                            ret = Check_name(Name);
                        }
                    } while (ret != STD_OK);


                    do
                    {
                        printf("Enter The Email: ");
                        if (fgets(Email, sizeof(Email), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Email[strcspn(Email, "\n")] = '\0';
                            ret = Check_Email(Email);
                        }
                    } while (ret != STD_OK);
                    do
                    {
                        ret = Check_Email_In_List(Email) ;
                    } while (ret != STD_OK);

                    do
                    {
                        printf("Enter The Phone Number: ");
                        if (fgets(Phone_Number, sizeof(Phone_Number), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Phone_Number[strcspn(Phone_Number, "\n")] = '\0';
                            ret = Check_PhoneNumber(Phone_Number);

                        }
                    } while (ret != STD_OK);
                    do
                    {
                        ret = Check_PhoneNumber_In_List(Phone_Number) ;
                    } while (ret != STD_OK);

                    ret = Contact_Add(Name ,Email ,Phone_Number) ;
                }
                else
                {
                    printf("Data Base Is Full Now ,Can't Add Another Elements.\n\n") ;
                }
                break;
            case 2:
                Len = Contact_List_Length() ;
                if(Len != 0)
                {
                    do
                    {
                        printf("Enter The Phone Number You Want To Remove : ");
                        if (fgets(Phone_Number, sizeof(Phone_Number), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Phone_Number[strcspn(Phone_Number, "\n")] = '\0';
                            ret = Check_PhoneNumber(Phone_Number);
                        }
                    } while (ret != STD_OK);

                    ret = Contact_Delete(Phone_Number) ;
                }
                else
                {
                    printf("Data Base Is Empty Now ,Can't Remove Any Contact. \n\n");
                }
                break;
            case 3:
                Len = Contact_List_Length() ;
                if(Len != 0)
                {
                    do
                    {
                        printf("Enter The Phone Number You Want To Update : ");
                        if (fgets(Phone_Number, sizeof(Phone_Number), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Phone_Number[strcspn(Phone_Number, "\n")] = '\0';
                            ret = Check_PhoneNumber(Phone_Number);
                        }
                    } while (ret != STD_OK);

                    ret = Contact_Search_Phone_Number(Phone_Number ,&Index) ;
                    if(ret != STD_NOT_FOUND)
                    {
                        do
                        {
                            fflush(stdin) ;
                            printf("Enter The New Phone Number : ");
                            if (fgets(Phone_Number, sizeof(Phone_Number), stdin) != NULL)
                            {
                                // Remove newline character from input if present
                                Phone_Number[strcspn(Phone_Number, "\n")] = '\0';
                                ret = Check_PhoneNumber(Phone_Number);
                            }
                        } while (ret != STD_OK);
                        ret = Contact_Update_Phone_Number(Phone_Number ,Index) ;
                    }
                    else
                    {
                        printf("This Phone Number Is Not Exist In the System. \n\n") ;
                    }
                }
                else
                {
                    printf("Data Base Is Empty Now ,Can't Update Any Contact. \n\n");
                }
                break;
            case 4:
                Len = Contact_List_Length() ;
                if(Len != 0)
                {
                    do
                    {
                        printf("Enter The Email You Want To Update : ");
                        if (fgets(Email, sizeof(Email), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Email[strcspn(Email, "\n")] = '\0';
                            ret = Check_Email(Email);
                        }
                    } while (ret != STD_OK);

                    ret = Contact_Search_Email(Email ,&Index) ;
                    if(ret != STD_NOT_FOUND)
                    {
                        do
                        {
                            fflush(stdin) ;
                            printf("Enter The New Email : ");
                            if (fgets(Email, sizeof(Email), stdin) != NULL)
                            {
                                // Remove newline character from input if present
                                Email[strcspn(Email, "\n")] = '\0';
                                ret = Check_Email(Email);
                            }
                        } while (ret != STD_OK);
                        ret = Contact_Update_Email(Email ,Index) ;
                    }
                    else
                    {
                        printf("This Email Is Not Exist In the System. \n\n") ;
                    }
                }
                else
                {
                    printf("Data Base Is Empty Now ,Can't Update Any Contact. \n\n");
                }
                break;
            case 5:
                Len = Contact_List_Length() ;
                if(Len != 0)
                {
                    do
                    {
                        fflush(stdin) ;
                        printf("Enter The Phone Number You Want To Search For It : ");
                        if (fgets(Phone_Number, sizeof(Phone_Number), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Phone_Number[strcspn(Phone_Number, "\n")] = '\0';
                            ret = Check_PhoneNumber(Phone_Number);
                        }
                    } while (ret != STD_OK);

                    ret = Contact_Search_Phone_Number(Phone_Number ,&Index) ;
                    if(ret != STD_NOT_FOUND)
                    {
                        printf("The Phone Number Is Exist in the System And he is in index : %d \n\n",Index) ;
                    }
                    else
                    {
                        printf("This Phone Number Is Not Exist In the System. \n\n") ;
                    }
                }
                else
                {
                    printf("Data Base Is Empty Now ,Can't Search For Any Contacts. \n\n");
                }
                break;
            case 6:
                Len = Contact_List_Length() ;
                if(Len != 0)
                {
                    do
                    {
                        fflush(stdin) ;
                        printf("Enter The Email You Want To Search For It : ");
                        if (fgets(Email, sizeof(Email), stdin) != NULL)
                        {
                            // Remove newline character from input if present
                            Email[strcspn(Email, "\n")] = '\0';
                            ret = Check_Email(Email);
                        }
                    } while (ret != STD_OK);

                    ret = Contact_Search_Email(Email ,&Index) ;
                    if(ret != STD_NOT_FOUND)
                    {
                        printf("The Email Is Exist in the System And he is in index : %d \n\n",Index) ;
                    }
                    else
                    {
                        printf("This Email Is Not Exist In the System. \n\n") ;
                    }
                }
                else
                {
                    printf("Data Base Is Empty Now ,Can't Search For Any Contacts. \n\n");
                }
                break;
            case 7:
                printf("\n");
                ret = Contact_Display_All();
                break;
            case 8:
                printf("\n\n");
                printf("-Uploading Data, Please Wait a Few Seconds");
                for (int i = 0; i < 16; i++)
                {
                    printf(".");
                    Sleep(150);
                }
                printf("\n\n");
                ret = Upload_Data();
                Exit();
                exit(1);
                break;

            default:
                break;
        }

    }
    return 0;
}

/**
 * @brief Displays the welcome message with a decorative border and a delay effect.
 *
 * This function prints a welcome message to the user, surrounded by a decorative border
 * made of asterisks. It also adds a delay effect to each printed character to create a
 * smooth and engaging animation.
 *
 * @param Welcome_Statement A pointer to the string containing the welcome message.
 * @param Count The initial index for the welcome message, typically starting at 0.
 */
static void Start_Program(char *Welcome_Statement, char Count)
{
    // Print the top border
    for (int i = 0; i < 70; i++)
    {
        printf("*");
        Sleep(11);
    }
    printf("\n\n\t\t");

    // Print the welcome statement with a delay for each character
    while (Welcome_Statement[Count])
    {
        printf("%c", Welcome_Statement[Count]);
        Sleep(10);
        Count++;
    }
    printf("\n\n");

    // Print the bottom border
    for (int i = 0; i < 70; i++)
    {
        printf("*");
        Sleep(15);
    }
    printf("\n\n");
}


/**
 * @brief Closes the system with a delay effect and prompts the user to press any key to exit.
 *
 * This function simulates the process of closing the system by printing a closing message with
 * a delay effect, followed by a prompt for the user to press any key to exit. It ensures a smooth
 * transition and clear indication to the user that the system is shutting down.
 */
static void Exit(void)
{
    // Print the closing message with a delay for each dot
    printf("Closing The System");
    for (int i = 0; i < 20; i++)
    {
        printf(".");
        Sleep(250);
    }
    printf("\n");

    // Prompt the user to press any key to exit
    printf("Press any Key To Exit...........");
    getchar();
    printf("==========================\n");
}
