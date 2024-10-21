#include <stdio.h>

void bubblesort(int*, int);
void printarray(int*, int);

int main() {
    int arr1[] = {3, 5, 1, 4, 2};
    int arr2[] = {-3, 5, 1, 4, 2, 0, -1};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int length2 = sizeof(arr2) / sizeof(arr1[0]);

    printf("Unsorted Array:");
    printarray(arr1, length1);
    bubblesort(arr1, length1);
    printf("\nSorted array:");
    printarray(arr1, length1);

    printf("\n\n");
    printf("Unsorted Array:");
    printarray(arr2, length2);
    bubblesort(arr2, length2);
    printf("\nSorted array:");
    printarray(arr2, length2);

    printf("\n");
    return 0;
}

void bubblesort(int arr[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void printarray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        if (i == 0)
            printf(" %d", arr[i]);
        else
            printf(", %d", arr[i]);
    }
}