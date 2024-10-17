#include <stdio.h>

int main() {
    int first, second, third;
    printf("First number: ");
    scanf("%d", &first);
    printf("Second number: ");
    scanf("%d", &second);
    printf("Third number: ");
    scanf("%d", &third);

    int *largest = NULL;
    if (first > second) {
        if (first > third) {
            largest = &first;
        } else {
            largest = &third;
        }
    } else {
        if (second > third) {
            largest = &second;
        } else {
            largest = &third;
        }
    }

    printf("Largest value: %d\n", *largest);
    return 0;
}
