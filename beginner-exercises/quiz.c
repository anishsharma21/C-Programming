#include <stdio.h>
#include <string.h>

void clearInputBuffer();

int main() {
    char questions[][50] = {"What is the first element in the periodic table?",
                            "How many bytes are used to represent an int in C?",
                            "How many endian-formats exist?"};
    char options[][4][10] = {
        {"Gold", "Helium", "Hydrogen", "Water"},
        {"32", "64", "unknown", "2"},
        {"3", "2", "1", "8"}};

    int answers[] = {3, 1, 2};

    int questionNum = 1;
    int numOfQs = sizeof(options) / sizeof(options[0]);
    int userChoice, correctCount = 0;

    while (questionNum <= numOfQs) {
        printf("%s\n\n", questions[questionNum - 1]);
        for (int i = 0; i < sizeof(options[0]) / sizeof(options[0][0]); i++) {
            printf("%d. %s\n", i + 1, options[questionNum - 1][i]);
        }

        printf("\nChoice: ");
        scanf("%d", &userChoice);
        clearInputBuffer();
        if (answers[questionNum - 1] == userChoice) {
            printf("Correct answer!\n\n");
            correctCount++;
        } else {
            printf("Incorrect answer...\n\n");
        }

        questionNum++;
    }

    printf("Total score: %d/%lu\n", correctCount, sizeof(options) / sizeof(options[0]));

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}