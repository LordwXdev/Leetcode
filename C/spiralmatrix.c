#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // allocate the matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) {
        // go right across the top row
        for (int col = left; col <= right; col++)
            matrix[top][col] = num++;
        top++;

        // go down the right column
        for (int row = top; row <= bottom; row++)
            matrix[row][right] = num++;
        right--;

        // go left across the bottom row
        for (int col = right; col >= left; col--)
            matrix[bottom][col] = num++;
        bottom--;

        // go up the left column
        for (int row = bottom; row >= top; row--)
            matrix[row][left] = num++;
        left++;
    }

    return matrix;
}

// helper to print the matrix
void printMatrix(int** matrix, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(",");
        }
        printf("]");
        if (i < n - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int returnSize;
    int* returnColumnSizes;

    // test n = 3
    int** result = generateMatrix(3, &returnSize, &returnColumnSizes);
    printf("n=3: ");
    printMatrix(result, 3);

    // free memory
    for (int i = 0; i < 3; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);

    // test n = 1
    result = generateMatrix(1, &returnSize, &returnColumnSizes);
    printf("n=1: ");
    printMatrix(result, 1);

    free(result[0]);
    free(result);
    free(returnColumnSizes);

    return 0;
}