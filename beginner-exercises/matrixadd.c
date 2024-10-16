#include <stdio.h>

void matrixadd(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns]);
void matrixaddp(int rows, int columns, int* matrix1, int* matrix2);
void printmatrix(int rows, int columns, int matrix[rows][columns]);

int main() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[3][3] = {
        {4, 6, -3},
        {0, -1, 9},
        {-9, -2, 4}
    };
    int rows = sizeof(matrix1) / sizeof(matrix1[0]);
    int columns = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);
    printmatrix(rows, columns, matrix1);
    printf("\n");
    printmatrix(rows, columns, matrix2);
    matrixadd(rows, columns, matrix1, matrix2);
    printf("\n");
    printmatrix(rows, columns, matrix1);
    matrixaddp(rows, columns, *matrix1, *matrix2);
    printf("\n");
    printmatrix(rows, columns, matrix1);
    return 0;
}

void matrixadd(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixaddp(int rows, int columns, int* matrix1, int* matrix2) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            *(matrix1 + i * columns + j) += *(matrix2 + i * columns + j);
        }
    }
}

void printmatrix(int rows, int columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j == 0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}