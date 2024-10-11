#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int guess = 0;
    srand(time(NULL));
    while (1) {
	int random = rand() % 10;
	printf("Guess: ");
	scanf("%d", &guess);
	printf("\n");
	if (random == guess) {
	    printf("Got it!\n");
	    break;
	}
	printf("Try again!\n\n");
    }
    return 0;
}
