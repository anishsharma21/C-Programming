#include <stdio.h>
#include <stdlib.h>

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
                printf("User choice is to view contacts\n");
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
                printf("HI\n");
                break;
        }
    }

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}