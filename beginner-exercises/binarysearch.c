#include <stdio.h>

int binarysearch(int* values, int* length, int* target);
void clearInputBuffer();

int main() {
    int values[] = {1, 3, 4, 7, 12, 14, 28};
    int valuesLength = sizeof(values) / sizeof(values[0]);

    int target;
    printf("Value to find: ");
    scanf("%d", &target);
    clearInputBuffer();

    int index = binarysearch(values, &valuesLength, &target);
    if (index >= 0 && index <= valuesLength - 1) {
        printf("Index of %d is %d\n", target, index);
    } else {
        printf("Index not found :(\n");
    }

    return 0;
}

int binarysearch(int* values, int* length, int* target) {
    int low = 0, high = *(length)-1, mid, curval;
    while (low <= high) {
        mid = (low + high) / 2;
        curval = *(values + mid);
        // printf("Low: %d, High: %d, Mid: %d, Curval: %d\n", low, high, mid, curval);
        if (curval == *(target))
            return mid;
        else if (curval < *(target))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}