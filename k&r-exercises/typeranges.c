#include <stdio.h>

void displayMinChar();
void displayMaxChar();
void displayMinUChar();
void displayMaxUChar();

int main() {
    displayMinChar();
    displayMaxChar();
    printf("\n");
    displayMinUChar();
    displayMaxUChar();
    return 0;
}

void displayMinChar() {
    char prev, a = 0;
    do {
        prev = a;
        a++;
    } while (prev < a);

    printf("MIN signed char: 0x%02x (%d)\n", (unsigned char)a, a);
}

void displayMaxChar() {
    char a, next = 0;
    do {
        a = next;
        next++;
    } while (next > a);

    printf("MAX signed char: 0x%02x (%d)\n", (unsigned char)a, a);
}

void displayMinUChar() {
    unsigned char prev, a = 0;
    do {
        prev = a;
        a++;
    } while (prev < a);

    printf("MIN signed char: 0x%02x (%d)\n", (unsigned char)a, a);
}

void displayMaxUChar() {
    unsigned char a = 0, prev = a;
    do {
        prev = a;
        a++;
    } while (a > prev);

    printf("MAX unsigned char: 0x%02x (%d)\n", (unsigned char)prev, prev);
}