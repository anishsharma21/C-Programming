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

    while (1) {
        printf("Guess: ");
        scanf("%d", &guess);
        clearInputBuffer();
        guesses++;

        if (guess == target) {
            printf("\nYou guessed right!\n");
            break;
        } else if (guess < target)
            printf("You guessed too LOW.\n");
        else
            printf("You guessed too HIGH.\n");
    }

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}