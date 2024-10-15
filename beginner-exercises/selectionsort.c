#include <stdio.h>

void printarr(int arr[], int length);
void selectionsort(int arr[], int length);

int main() {
    int arr1[] = { 3, 2, 5, 1, 4 };
    int length = sizeof(arr1) / sizeof(int);
    printf("Initial array:");
    printarr(arr1, length);
    selectionsort(arr1, length);
    printf("Sorted array:");
    printarr(arr1, length);
    return 0;
}

void printarr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            printf(" %d", arr[i]);
        }
        else {
            printf(", %d", arr[i]);
        }
    }
    printf("\n");
}

void selectionsort(int arr[], int length) {
    int j;
    for (int i = 1; i < length; i++) {
        int temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}