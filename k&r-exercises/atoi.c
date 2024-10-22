#include <stdio.h>

int atoi(char string[]);
int atoi2(char s[]);

int main() {
    int num = atoi("12341123");
    printf("Number: %d\n", num);

    num = atoi2("12343");
    printf("Number: %d\n", num);
    return 0;
}

int atoi(char string[]) {
    int i = 0, n = 0;
    while (string[i] != '\0' && string[i] < '9') {
        n = n * 10 + string[i] - '0';
        i++;
    }
    return n;
}

int atoi2(char s[]) {
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = n * 10 + (s[i] - '0');
    return n;
}