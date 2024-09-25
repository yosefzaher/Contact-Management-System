#ifndef _MAIN_H_
#define _MAIN_H_


#include "contact_layer/Check_Data_Module/Check_Data.h"
#include "contact_layer/Contact_Info_Module/Contact_Info.h"

extern Contact_Info_t *ListHead  ;
extern FILE *DataBase_File  ;


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
static void Start_Program(char *Welcome_Statement, char Count) ;


/**
 * @brief Closes the system with a delay effect and prompts the user to press any key to exit.
 *
 * This function simulates the process of closing the system by printing a closing message with
 * a delay effect, followed by a prompt for the user to press any key to exit. It ensures a smooth
 * transition and clear indication to the user that the system is shutting down.
 */
static void Exit(void) ;

#endif // _MAIN_H_
