#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[16];
    int age;
    char phoneNumber[16];
    char email[32];
} Contact;

int main() {
    Contact c1 = {"Anish", 21, "044444444", "anish@gmail.com"};
    printf("Name: %s, Age: %d, Phone Number: %s, Email: %s\n", c1.name, c1.age, c1.phoneNumber, c1.email);

    Contact* c2 = (Contact*)malloc(sizeof(Contact));
    if (c2 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    snprintf(c2->name, sizeof(c2->name), "Kai");
    c2->age = 22;
    snprintf(c2->phoneNumber, sizeof(c2->phoneNumber), "0144444444");
    snprintf(c2->email, sizeof(c2->email), "kai@gmail.com");
    printf("Name: %s, Age: %d, Phone Number: %s, Email: %s\n", c2->name, c2->age, c2->phoneNumber, c2->email);

    return 0;
}