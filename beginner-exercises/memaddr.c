#include <stdint.h>
#include <stdio.h>

void printbinary(uintptr_t);

int main() {
    char x = 'X';
    char y = 'Y';
    char z = 'Z';

    printf("Size of 'x': %d bytes\n", (int)sizeof(x));
    printf("Size of 'y': %d bytes\n", (int)sizeof(y));
    printf("Size of 'z': %d bytes\n", (int)sizeof(z));

    printf("\n");
    printf("Address of 'x' is: %p\n", (void *)&x);
    printf("Address of 'y' is: %p\n", (void *)&y);
    printf("Address of 'z' is: %p\n", (void *)&z);

    printf("\n");
    printf("Address of 'x' in binary: ");
    printbinary((uintptr_t)&x);
    printf("Address of 'y' in binary: ");
    printbinary((uintptr_t)&y);
    printf("Address of 'z' in binary: ");
    printbinary((uintptr_t)&z);

    printf("\n");
    printf("Size of char: %lu\nSize of short: %lu\nSize of int: %lu\nSize of long: %lu\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long));

    int a = 21;
    int *pA = &a;
    printf("\n");
    printf("Value of 'a': %d\n", a);
    printf("Address of 'a': %p\n", &a);
    printf("Value stored at pointer: %d\n", *pA);
    printf("Value of pointer: %p\n", pA);

    char arr1[3];
    short arr2[] = {1, 2, 3};

    printf("\n");
    printf("Size of in arr1: %lu\n", sizeof(arr1));
    printf("Memory addresses of arr1: %p, %p, %p\n", &arr1[0], &arr1[1], &arr1[2]);
    printf("Size of in arr2: %lu\n", sizeof(arr2));
    printf("Memory addresses of arr1: %p, %p, %p\n", &arr2[0], &arr2[1], &arr2[2]);

    return 0;
}

void printbinary(uintptr_t n) {
    int bit;
    for (int i = sizeof(uintptr_t) * 8 - 1; i >= 0; i--) {
        bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}