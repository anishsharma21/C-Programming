#include <stdio.h>

int findsumofdigits(int num) {
    int sum = 0;
    for (int i = 1; i - num < 0; i *= 10) {
        int rem = num % (i * 10);
        num -= rem;
        sum += rem / i;
    }
    return sum;
}

int main() {
    int input = 0;
    printf("Enter a number: ");
    scanf("%d", &input);

    int dsum = findsumofdigits(input);
    printf("Sum of digits: %d\n", dsum);

    return 0;
}