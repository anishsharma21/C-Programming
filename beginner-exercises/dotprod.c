#include <stdio.h>

int* matrixdotproduct(int rows1, int columns1, int rows2, int columns2, int matrix1[rows1][columns1], int matrix2[rows2][columns2], int finalmatrix[rows1][columns2]);

int main() {
    int matrix1[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
    };
    int matrix2[2][3] = {
        {5, 2, 1},
        {3, 1, 1},
    };
    int rows1 = sizeof(matrix1) / sizeof(matrix1[0]);
    printf("Rows1: %d\n", rows1);
    int columns1 = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);
    int rows2 = sizeof(matrix2) / sizeof(matrix2[0]);
    int columns2 = sizeof(matrix2[0]) / sizeof(matrix2[0][0]);
    printf("Columns2: %d\n", columns2);
    int finalmatrix[rows1][columns2];
    int* finalmatrixp = matrixdotproduct(rows1, columns1, rows2, columns2, matrix1, matrix2, finalmatrix);

    printf("Matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            if (j == 0)
                printf("%d", *(finalmatrixp + i * columns2 + j));
            else
                printf(" %d", *(finalmatrixp + i * columns2 + j));
        }
        printf("\n");
    }

    return 0;
}

int* matrixdotproduct(int rows1, int columns1, int rows2, int columns2, int matrix1[rows1][columns1], int matrix2[rows2][columns2], int finalmatrix[rows1][columns2]) {
    if (rows1 != columns2) {
        printf("Matrix dimensions are invalid: %d rows of m1 do not match %d of m2\n", rows1, columns2);
        return 0;
    }

    int temp;

    for (int i = 0; i < rows1; i++) {
        for (int k = 0; k < columns2; k++) {
            temp = 0;
            for (int l = 0; l < rows2; l++) {
                temp += matrix1[i][l] * matrix2[l][k];
            }
            finalmatrix[i][k] = temp;
        }
    }

    return *finalmatrix;
}