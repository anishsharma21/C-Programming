#include <stdio.h>

int main() {
    int integer;

    printf("Type in an integer: ");
    scanf("%d", &integer);

    if (integer % 2 == 0) {
        printf("%d is even\n", integer);
    } else {
        printf("%d is odd\n", integer);
    }

    return 0;
}
