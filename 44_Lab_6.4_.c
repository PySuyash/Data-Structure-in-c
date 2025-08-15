// Create Matrix Rows, Write: void createMatrixRows(int ***rows, int rowCount, int colCount), Allocates rowCount pointers (simulate row pointers). Each row allocated later.

#include <stdio.h>
#include <stdlib.h>

// Allocates rowCount pointers and each row with colCount integers
void createMatrixRows(int ***rows, int rowCount, int colCount) {
    *rows = (int **)malloc(rowCount * sizeof(int *));
    if (*rows == NULL) {
        printf("Failed to allocate row pointers.\n");
        exit(1);
    }

    for (int i = 0; i < rowCount; i++) {
        (*rows)[i] = (int *)malloc(colCount * sizeof(int));
        if ((*rows)[i] == NULL) {
            printf("Failed to allocate row %d.\n", i);
            exit(1);
        }
    }
}

// Prints the matrix
void printMatrix(int **matrix, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowCount = 3, colCount = 4;
    int **matrix;

    createMatrixRows(&matrix, rowCount, colCount);

    // Fill matrix with sample values
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = i * colCount + j + 1;
        }
    }

    printf("Matrix:\n");
    printMatrix(matrix, rowCount, colCount);

    // Free memory
    for (int i = 0; i < rowCount; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
