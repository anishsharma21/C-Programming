#include <stdio.h>

typedef struct {
    char name[16];
    int age;
    char phoneNumber[16];
    char email[32];
} Contact;

int main() {
    Contact c1 = {"Anish", 21, "044444444", "anish@gmail.com"};
    printf("Name: %s, Age: %d\n", c1.name, c1.age);
    printf("Size of Contact object: %lu\n", sizeof(Contact));
    printf("Size of c1 Contact object: %lu\n", sizeof(c1));
    return 0;
}