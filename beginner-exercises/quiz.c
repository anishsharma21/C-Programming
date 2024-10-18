#include <stdio.h>
#include <string.h>

typedef struct {
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
} Option;

int main() {
    char questions[][100] = {"What is the first element in the periodic table?",
                             "How many bytes are used to represent an int in C?",
                             "How many endian-formats exist?"};
    Option options[] = {
        {"Gold", "Helium", "Hydrogen", "Water"},
        {"32", "64", "unknown", "2"},
        {"3", "2", "1", "8"}};

    for (int i = 0; i < sizeof(options) / sizeof(options[0]); i++) {
        for (int j = 0; j < sizeof(options[0]) / sizeof(options[0].option1); j++) {
            char answer[100];
            strcpy(answer, (void *)&options[i] + sizeof(options[0].option1) * j);
            printf("%s\n", answer);
        }
    }

    return 0;
}