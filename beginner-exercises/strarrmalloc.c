#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numberOfStrings = 5;
    int maxLength = 64;

    char** stringArr = (char**)malloc(numberOfStrings * sizeof(char*));

    for (int i = 0; i < numberOfStrings; i++) {
        stringArr[i] = (char*)malloc(maxLength * sizeof(char));
    }

    strcpy(stringArr[0], "hello");
    printf("Allocated string: %s\n", stringArr[0]);

    for (int i = 0; i < numberOfStrings; i++) {
        free(stringArr[i]);
    }
    free(stringArr);

    return 0;
}
