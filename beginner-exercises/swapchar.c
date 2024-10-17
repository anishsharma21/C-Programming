#include <stdio.h>

int main() {
    char X = 'X', Y = 'Y';
    char temp = Y;
    Y = X;
    X = temp;
    printf("%c, %c\n", X, Y);
    return 0;
}