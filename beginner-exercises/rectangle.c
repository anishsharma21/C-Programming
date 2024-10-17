#include <stdio.h>

void clearInputBuffer();

int main() {
    int rows, columns;
    char symbol;

    printf("Enter # for rows: ");
    scanf("%d", &rows);
    printf("Enter # for columns: ");
    scanf("%d", &columns);
    clearInputBuffer();
    printf("Enter a symbol: ");
    scanf("%c", &symbol);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}