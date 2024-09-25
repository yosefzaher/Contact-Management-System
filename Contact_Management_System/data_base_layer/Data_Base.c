#include "Data_Base.h"

/**
 * @brief  : Load all contacts from the CSV file into the linked list.
 * @param  : (ListHead) Pointer to the head of the linked list.
 * @param  : (filename) Name of the CSV file to load data from.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Load_Contacts_From_File(Contact_Info_t **ListHead, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return STD_ERROR;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        char name[100], email[50], phone_number[12];
        if (sscanf(buffer, "%[^,],%[^,],%s", name, email, phone_number) != 3) {
            continue; // Skip malformed lines
        }
        Insert_At_End(ListHead, (int8_t *)name, (int8_t *)email, (int8_t *)phone_number);
    }

    fclose(file);
    return STD_OK;
}

/**
 * @brief  : Save all contacts from the linked list into the CSV file.
 * @param  : (ListHead) Pointer to the head of the linked list.
 * @param  : (filename) Name of the CSV file to save data to.
 * @return : (STD_OK) if the operation is successful, otherwise (STD_ERROR).
 */
Std_ReturnType Save_Contacts_To_File(Contact_Info_t *ListHead, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return STD_ERROR;
    }

    Contact_Info_t *current = ListHead;
    while (current) {
        fprintf(file, "%s,%s,%s\n", current->Name, current->Email, current->Phone_Number);
        current = current->Next_Contact;
    }

    fclose(file);
    return STD_OK;
}

