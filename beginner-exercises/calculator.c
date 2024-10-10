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

    switch (operation) {
	case '+':
	    firstInt += secondInt;
	    break;
	case '-':
	    firstInt -= secondInt;
	    break;
	case '*':
	    firstInt *= secondInt;
	    break;
	case '/':
	    firstInt /= secondInt;
	    break;
	default:
	    break;
    }

    printf("Output: %d\n", firstInt);

    return 0;
}
