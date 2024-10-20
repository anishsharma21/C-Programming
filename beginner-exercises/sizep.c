#include <stdio.h>

int main() {
    int x = 12;
    int* pX = &x;

    printf("Size of x: %lu\n", sizeof(x));
    printf("Size of pX: %lu\n", sizeof(pX));

    return 0;
}