#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;

    int* result = (int*)malloc(m * n * sizeof(int));
    int idx = 0;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // go right along top row
        for (int i = left; i <= right; i++)
            result[idx++] = matrix[top][i];
        top++;

        // go down along right column
        for (int i = top; i <= bottom; i++)
            result[idx++] = matrix[i][right];
        right--;

        // go left along bottom row (only if rows remain)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[idx++] = matrix[bottom][i];
            bottom--;
        }

        // go up along left column (only if columns remain)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[idx++] = matrix[i][left];
            left++;
        }
    }

    return result;
}

int main() {
    int rows1 = 3, cols1 = 3;
    int data1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int* matrix1[3];
    for (int i = 0; i < rows1; i++) matrix1[i] = data1[i];

    int returnSize;
    int colSizes1[] = {cols1, cols1, cols1};
    int* out1 = spiralOrder((int**)matrix1, rows1, colSizes1, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
        printf(i < returnSize - 1 ? "%d," : "%d", out1[i]);
    printf("]\n");
    free(out1);

    return 0;
}