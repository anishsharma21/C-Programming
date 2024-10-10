#include <stdio.h>

int main() {
    int firstInt;
    int secondInt;
    char operation;

    printf("Type in an integer: ");
    scanf("%d", &firstInt);

    printf("Type in an operation: ");
    scanf(" %c", &operation);

    printf("Type in another integer: ");
    scanf("%d", &secondInt);

    if (operation == '+') {
	printf("Output: %d", firstInt + secondInt);
    }
    else if (operation == '-') {
	printf("Output: %d", firstInt - secondInt);
    }
    else if (operation == '*') {
	printf("Output: %d", firstInt * secondInt);
    }
    else if (operation == '/') {
	printf("Output: %d", firstInt / secondInt);
    }
    else {
	printf("Can't do that operation.");
    }

    printf("\n");
    return 0;
}
