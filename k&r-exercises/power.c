#include <stdio.h>

int power(int base, int pow);

int main() {
    for (int i = 0; i < 5; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int pow) {
    int p = 1;
    for (int i = 0; i < pow; i++) {
        p *= base;
    }
    return p;
}
