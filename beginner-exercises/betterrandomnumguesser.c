#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInputBuffer();

int main() {
    const int MIN = 1;
    const int MAX = 100;
    int guess = MIN - 1, guesses;

    srand(time(0));
    int target = (rand() % MAX) + MIN;

    do {
        printf("Guess: ");
        scanf("%d", &guess);
        clearInputBuffer();
        if (guess > target)
            printf("Guess was too HIGH.\n");
        else
            printf("Guess was too LOW.\n");
        guesses++;
    } while (guess != target);

    printf("\nAnswer: %d\n", target);
    printf("Guesses: %d\n", guesses - 1);

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}