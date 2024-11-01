#include <stdio.h>

#define NUMBER_OF_CONTACT_ATTRIBUTES 4

void viewContacts();
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
                break;
            case 'd':
                printf("User choice is to delete a contact\n");
                break;
            case 'q':
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
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
