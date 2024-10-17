#include <stdio.h>
#include <string.h>

int main() {
    char name[25];

    do {
        printf("Type in a name: ");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
    } while (strlen(name) < 5);

    printf("Hi %s\n", name);
    return 0;
}