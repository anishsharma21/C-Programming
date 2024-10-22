#include <stdio.h>

int my_strlen(char string[]);

int main() {
    char name[] = "Anish", empty[] = "", longer[] = "bottle of water init";
    printf("Length of name string: %d\n", my_strlen(name));
    printf("Length of empty string: %d\n", my_strlen(empty));
    printf("Length of longer string: %d\n", my_strlen(longer));
    return 0;
}

int my_strlen(char string[]) {
    int len = 0;
    while (string[len] != '\0')
        len++;
    return len;
}