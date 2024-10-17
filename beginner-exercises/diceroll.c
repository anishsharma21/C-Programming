#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int diceroll;
    do {
        diceroll = rand() % 6 + 1;
        printf("Roll: %d\n", diceroll);
    } while (diceroll != 6);

    return 0;
}