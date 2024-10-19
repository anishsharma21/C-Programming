#include <stdio.h>

void printbinary(int value);

int main() {
    int x = 12;
    int y = 5;

    printbinary(x & y);
    printbinary(x | y);
    printbinary(x ^ y);
    printbinary(~x);
    printbinary(x << 1);
    printbinary(x << 2);
    printbinary(x << 3);

    return 0;
}

void printbinary(int n) {
    int bit;
    for (int i = sizeof(int) * 2 - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}