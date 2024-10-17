#include <stdio.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'

int winner(char *board) {
    if (
        *(board) == *(board + 1) && *(board) == *(board + 2) ||
        *(board + 3) == *(board + 4) && *(board + 3) == *(board + 5) ||
        *(board + 6) == *(board + 7) && *(board + 6) == *(board + 8) ||
        *(board) == *(board + 3) && *(board) == *(board + 6) ||
        *(board + 1) == *(board + 4) && *(board + 1) == *(board + 7) ||
        *(board + 2) == *(board + 5) && *(board + 2) == *(board + 8) ||
        *(board) == *(board + 4) && *(board) == *(board + 8) ||
        *(board + 6) == *(board + 4) && *(board + 6) == *(board + 2)) {
        return 1;
    }
    return 0;
}

void displayBoard(char *board) {
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

void displayPositions(int *openPositions) {
    int firstValuePrinted = 0;
    for (int i = 0; i < 9; i++) {
        if (*(openPositions + i) != 0) {
            if (i != 0 && firstValuePrinted)
                printf(", ");
            printf("%d", *(openPositions + i));
            firstValuePrinted = 1;
        }
    }
    printf("\n");
}

int validatePosition(int *chosenPos, int *openPositions) {
    for (int i = 0; i < 9; i++) {
        if (openPositions[i] != 0)
            if (*chosenPos == openPositions[i]) {
                openPositions[i] = 0;
                return 1;
            }
    }
    return 0;
}

int gameEnd(int *positions) {
    for (int i = 0; i < 9; i++) {
        if (positions[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    char curPlayer = PLAYER_X;
    int openPositions[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int posChoice = 0;
    int inputRow, inputColumn;

    printf("### TIC TAC TOE ###\n\n");

    while (1) {
        displayBoard(&board[0][0]);
        printf("\nChoose a position for '%c': ", curPlayer);
        displayPositions(&openPositions[0]);
        printf("Choice: ");

        if ((scanf("%d", &posChoice)) != 1) {
            printf("\n### Invalid input for position entered. Please enter a number. ###\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (posChoice == 0) {
            break;
        }

        int isValidPos = validatePosition(&posChoice, &openPositions[0]);
        if (!isValidPos) {
            printf("\n### Invalid position entered: %d ###\n\n", posChoice);
            continue;
        }

        posChoice--;
        inputRow = posChoice / 3;
        inputColumn = posChoice % 3;

        board[inputRow][inputColumn] = curPlayer;

        if (winner(&board[0][0])) {
            printf("\n### Congratulations %c, you won! ###\n", curPlayer);
            break;
        }

        if (gameEnd(&openPositions[0])) {
            printf("\nNo more positions available... game over!\n");
            break;
        }

        curPlayer = curPlayer == PLAYER_X ? PLAYER_O : PLAYER_X;
    }

    return 0;
}