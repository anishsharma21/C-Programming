#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int total_len, len, max;
    char line[MAXLINE], longest[MAXLINE];
    int is_continuation;

    max = is_continuation = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (is_continuation) {
            total_len += len;
        } else {
            total_len = len;
        }
        if (line[len - 1] != '\n') {
            is_continuation = 1;
        }
        else {
            is_continuation = 0;
            printf("Line length: %d\n", len);
            if (total_len > max) {
                max = total_len;
                copy(longest, line);
            }
            total_len = 0;
        }
    }
    if (max > 0) {
        printf("\nLongest line: %s", longest);
        printf("Length: %d\n", max);
    }
    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
