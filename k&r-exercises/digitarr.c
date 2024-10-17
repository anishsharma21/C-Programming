#include <stdio.h>

int main() {
    int ndigits[10];
    for (int i = 0; i < 10; i++)
        ndigits[i] = i;
    printf("Digits:");
    for (int i = 0; i < 10; i++)
        printf(" %d", i);
    printf("\n");
    return 0;
}
