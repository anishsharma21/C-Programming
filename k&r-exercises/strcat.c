#include <stdio.h>

void mystrcat(char* s1, char* s2);

int main() {
    char s1[64];
    char s2[] = "name is anish";
    s1[0] = 'M';
    s1[1] = 'y';
    s1[2] = ' ';

    printf("Before concat\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n\n", s2);

    mystrcat(s1, s2);

    printf("After concat\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n\n", s2);

    return 0;
}

void mystrcat(char* s1, char* s2) {
    int startConcat = 0;
    while (s1[startConcat] != '\0')
        startConcat++;
    for (int i = 0; s2[i] != '\0'; i++)
        s1[startConcat++] = s2[i];
}