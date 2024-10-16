#include <stdio.h>
#include <stdlib.h>

#define CONTINUE 1
#define END 0
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define NONE -1
#define VALID_POS 1
#define INVALID_POS 0

void displayBoard(char* board);
void displayPositions(int* openPositions);
int validatePosition(int* chosenPos, int* openPositions);
int winner(char* board, int* winner);

int main() {
    char board[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
    };
    int openPositions[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int gameStatus = CONTINUE;
    int winnerName = NONE;
    char curPlayer = PLAYER_X;
    int posChoice = 0;

    printf("### TIC TAC TOE ###\n\n");

    while (gameStatus) {
        displayBoard(&board[0][0]);
        printf("\nChoose a position for '%c': ", curPlayer);
        displayPositions(&openPositions[0]);
        printf("Choice: ");
        scanf("%d", &posChoice);
        gameStatus = END;
    }

    return 0;
}

void displayBoard(char* board) {
    printf("---------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 0)
                printf(" ");
            printf("%c", *(board + 3 * i + j));
            if (j < 2)
                printf(" |");
        }
        printf("\n---------\n");
    }
}

void displayPositions(int* openPositions) {
    for (int i = 0; i < 9; i++) {
        if (*(openPositions + i) != 0) {
            if (i != 0)
                printf(", ");
            printf("%d", *(openPositions + i));
        }
    }
    printf("\n");
}

int validatePosition(int* chosenPos, int* openPositions)
{
    for (int i = 0; i < 9; i++) {
        if (*(openPositions + i) != 0)
            if (*chosenPos == *(openPositions + i))
                return VALID_POS;
    }
    return INVALID_POS;
}
