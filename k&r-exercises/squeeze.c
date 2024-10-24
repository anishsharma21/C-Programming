#include <stdio.h>

void squeeze(char* s, char c);

int main() {
    char sentence[] = "Hi there my name is Anish";
    char removeC = 'n';

    printf("Sentence before squeeze: %s\n", sentence);
    squeeze(sentence, removeC);
    printf("Sentence after squeeze: %s\n", sentence);

    return 0;
}

void squeeze(char* s, char c) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] != c)
            s[j++] = s[i];
        i++;
    }
    s[j] = '\0';
}