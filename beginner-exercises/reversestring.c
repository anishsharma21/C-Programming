#include <stdio.h>

void reverseString(char string[], int length) {
    char temp;
    for (int i = 0; i < (length - 1) / 2; i++) {
        temp = string[i];
        string[i] = string[length - i - 2];
        string[length - i - 2] = temp;
    }
}

int main() {
    char string[] = "bottle";
    int stringLength = sizeof(string) / sizeof(char);
    printf("Initial string: %s\n", string);
    reverseString(string, stringLength);
    printf("Reversed string: %s\n", string);
    return 0;
}