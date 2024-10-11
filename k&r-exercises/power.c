#include <stdio.h>

void power(int *base, int *pow);

int main() {
    int base, pow;
    printf("Type in the base: ");
    scanf("%d", &base);
    printf("Type in the power: ");
    scanf("%d", &pow);
    power(&base, &pow);
    printf("Result: %d\n", base);
    printf("New values: %d %d\n", base, pow);
}

void power(int *base, int *pow) {
    int result = 1;
    for (int i = 0; i < *pow; i++)
	result *= (*base);
    *base = result;
}
