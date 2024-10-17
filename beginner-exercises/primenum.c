#include <stdbool.h>
#include <stdio.h>

bool prime(int num) {
    for (int i = 2; i < num; i++) {
        if (i * i > num)
            return true;
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    bool isPrime = 0;
    printf("Which number to check: ");
    scanf("%d", &num);
    if (num > 1) {
        isPrime = prime(num);
    }
    if (isPrime) {
        printf("%d is prime\n", num);
    } else {
        printf("%d is not prime\n", num);
    }
    return 0;
}
