#include <stdio.h>
#include <stdlib.h>

int htoi(char hex[], int len);
int htoix(char hex[], int len);

int main() {
    char hex1[] = "F0";
    char hex2[] = "CAFE";
    char hex3[] = "0CAFE";
    char hex4[] = "HAHA";
    char hex5[] = "123555L";

    printf("Hexadecimal: %s, Integer: %d\n", hex1, htoi(hex1, 2));
    printf("Hexadecimal: %s, Integer: %d\n", hex2, htoi(hex2, 4));
    printf("Hexadecimal: %s, Integer: %d\n", hex3, htoi(hex3, 5));
    printf("Hexadecimal: %s, Integer: %d\n", hex4, htoi(hex4, 4));
    printf("Hexadecimal: %s, Integer: %d\n", hex5, htoi(hex5, 7));

    return 0;
}

int htoi(char hex[], int len) {
    int n = 0;
    for (int i = 0; i < len; i++) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            n = n * 16 + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            n = n * 16 + c - 'A' + 10;
        } else {
            fprintf(stderr, "Error: Invalid hex character '%c' at position %d.\n", c, i);
            return -1;
        }
    }
    return n;
}