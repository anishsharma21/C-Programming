#include <stdio.h>
#include <stdlib.h>

int* allocateInt(int value);
int* allocateIntArr(int size);
int* reallocateIntArr(int* intArrPointer, int newSize);
void displayArr(int* intArrPointer, int size);

int main() {
    int size = 1;

    printf("Size of int array: ");
    scanf("%d", &size);

    int* intPointer = allocateInt(size);
    printf("\nInteger value: %d\nInteger address: %p\n", *intPointer, intPointer);
    printf("Address of the pointer: %p\n", &intPointer);

    int* intArrPointer = allocateIntArr(size);
    printf("\nInteger array: ");
    displayArr(intArrPointer, size);

    printf("\nNew size of int array: ");
    scanf("%d", &size);
    intArrPointer = reallocateIntArr(intArrPointer, size);

    printf("\nInteger array: ");
    displayArr(intArrPointer, size);

    return 0;
}

int* allocateInt(int value) {
    int* intPointer = (int*)malloc(sizeof(int));
    *intPointer = value;
    return intPointer;
}

int* allocateIntArr(int size) {
    int* intArrPointer = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        intArrPointer[i] = i + 1;
    return intArrPointer;
}

int* reallocateIntArr(int* intArrPointer, int newSize) {
    int* newIntArrPointer = realloc(intArrPointer, newSize);
    if (newIntArrPointer == NULL) {
        perror("\nrealloc attempt failed at pointer\n");
    }
    return newIntArrPointer;
}

void displayArr(int* intArrPointer, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0)
            printf("%d", intArrPointer[i]);
        else
            printf(", %d", intArrPointer[i]);
    }
    printf("\n");
}