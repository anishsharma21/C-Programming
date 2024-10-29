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
    do {
        printf("v - View contacts\na - Add\nd - Delete\nq - Quit\n");
        printf("\nInput: ");
        userChoice = getchar();
        clearInputBuffer();
    } while (userChoice != 'q');

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}