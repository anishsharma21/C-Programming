#include <stdio.h>
#include <stdlib.h>

void fib(int num);
void fib2(int num, int arr[]);
void fib3(int *num, int low, int high);
void printarr(int arr[], int length);

int main() {
    int num = 1;
    printf("How many fib nums? ");
    scanf("%d", &num);

    fib(num);

    int *arr = (int *)malloc(num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fib2(num, arr);
    printarr(arr, num);

    free(arr);

    fib3(&num, 1, 1);

    return 0;
}

void fib(int num) {
    int prev = 0, cur = 1;

    for (int i = 0; i < num; ++i) {
        printf("%d ", cur);
        int temp = cur;
        cur = prev + cur;
        prev = temp;
    }
    printf("\n");
}

void fib2(int num, int arr[]) {
    if (num < 1)
        return;
    arr[0] = 1;
    if (num < 2)
        return;
    arr[1] = 1;
    for (int i = 2; i < num; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

void fib3(int *num, int low, int high) {
    if (*num < 1) {
        return;
    }
    if (*num < 2) {
        printf("%d\n", low);
        return;
    }
    printf("%d ", low);
    int temp = high;
    high += low;
    *num -= 1;
    return fib3(num, temp, high);
}

void printarr(int arr[], int length) {
    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}