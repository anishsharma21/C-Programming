#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_CONTACT_ATTRIBUTES 4

void viewContacts();
void addContact();
void deleteContact();
void clearInputBuffer();

typedef struct {
    char name[16];
    int age;
    char phoneNumber[16];
    char email[32];
} Contact;

int main() {
    printf("*************************\n");
    printf("Contact Management System\n");
    printf("*************************\n\n");

    char userChoice;
    while (1) {
        printf("v - View contacts\na - Add\nd - Delete\nq - Quit\n");
        printf("\nInput: ");
        userChoice = getchar();
        clearInputBuffer();
        printf("\n");

        switch (userChoice) {
            case 'v':
                printf("User choice is to view contacts\n\n");
                viewContacts();
                break;
            case 'a':
                printf("User choice is to add a new contact\n");
                addContact();
                break;
            case 'd':
                printf("User choice is to delete a contact\n");
                deleteContact();
                break;
            case 'q':
                system("clear");
                return 0;
            default:
                printf("Choose a valid option (v, a, d, q)\n");
                break;
        }
    }

    return 0;
}

// we want to display first name, last name, age, and email
void viewContacts() {
    system("clear");
    FILE* pF;
    pF = fopen("contacts.txt", "r");
    if (pF == NULL) {
        fprintf(stderr, "Error opening contacts file.\n");
        return;
    }
    printf("Contacts:\n");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), pF) != NULL) {
        for (int i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] == '\0')
                break;
            if (buffer[i] == ',') {
                printf("\t");
                continue;
            }
            printf("%c", buffer[i]);
        }
        printf("\n");
    }
    fclose(pF);
}

void addContact() {
    system("clear");
    FILE* pF;
    pF = fopen("contacts.txt", "a");
    if (pF == NULL) {
        fprintf(stderr, "Error opening contacts file.\n");
        return;
    }

    char buffer[50];
    char prompts[][16] = {"First name: ", "Last name: ", "Age: ", "Email: "};
    for (int i = 0; i < NUMBER_OF_CONTACT_ATTRIBUTES; i++) {
        printf("%s", prompts[i]);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            fprintf(pF, "%s", buffer);
            if (i + 1 != NUMBER_OF_CONTACT_ATTRIBUTES)
                fprintf(pF, ",");
        }
    }
    fprintf(pF, "\n");
    fclose(pF);

    printf("\nAdded contact successfully!\n");
}

void deleteContact() {
    system("clear");
    FILE* pF;
    FILE* tempF;
    pF = fopen("contacts.txt", "r");
    if (pF == NULL) {
        perror("Error opening contacts file.\n");
        return;
    }

    tempF = fopen("temp.txt", "w");
    if (tempF == NULL) {
        perror("Error opening temporary file.\n");
        fclose(pF);
        return;
    }

    char name[64];
    printf("Name of contact to delete: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        name[strcspn(name, "\n")] = 0;

        char line[256];
        int found = 0;
        while (fgets(line, sizeof(line), pF)) {
            char tempName[64];
            sscanf(line, "%63[^,]", tempName);
            if (strcmp(name, tempName) != 0) {
                fputs(line, tempF);
            } else {
                found = 1;
            }
        }

        if (found) {
            printf("Contact deleted successfully.\n");
        } else {
            printf("Name not found...\n");
        }
    } else {
        perror("Invalid name.\n");
    }

    fclose(pF);
    fclose(tempF);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
