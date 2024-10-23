#include <ctype.h>
#include <stdio.h>

char lower(char c);

int main() {
    char a;

    printf("Type in a single character: ");
    scanf("%c", &a);

    printf("Lower case of '%c': %c\n", a, lower(a));
    printf("Lower case of '%c': %c\n", a, tolower(a));
    return 0;
}

char lower(char c) {
    if (c >= 'A' && c <= 'Z')
        c += 'a' - 'A';
    return c;
}