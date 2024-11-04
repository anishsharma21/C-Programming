#include <stdio.h>
#include <stdlib.h>

char* mystrdup(char* s, int len);
int mystrlen(char* s);
void replaceNewlineWithNull(char* s);
void displayStrBytes(char* s, int length);

int main() {
    char string[16];
    printf("String: ");
    fgets(string, 16, stdin);
    int length = mystrlen(string);
    displayStrBytes(string, length);
    replaceNewlineWithNull(string);
    displayStrBytes(string, length);
    char* dupstring = mystrdup(string, length);
    displayStrBytes(dupstring, length);

    free(dupstring);

    return 0;
}

char* mystrdup(char* s, int len) {
    char* dupstr = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
        dupstr[i] = s[i];
    return dupstr;
}

int mystrlen(char* s) {
    int len;
    while (s[len++] != '\0');
    return len - 1;
}

void replaceNewlineWithNull(char* s) {
    int i;
    while (s[i++] != '\n');
    s[i - 1] = '\0';
}

void displayStrBytes(char* s, int length) {
    printf("\nBytes: ");
    for (int i = 0; i < length; i++)
        printf("%d ", s[i]);
    printf("\n");
}