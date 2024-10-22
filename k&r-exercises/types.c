#include <stdio.h>

int main() {
    const char a;
    const short b;
    const int c;
    const int32_t d;
    const int64_t e;

    printf("Size of int: %lu\n", sizeof(c));
    printf("Size of int: %lu\n", sizeof(d));
    printf("Size of int: %lu\n", sizeof(e));
    printf("Size of void *: %lu\n", sizeof(void *));

    return 0;
}
