#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cols[i] = which column the queen in row i is placed
int cols[10];
int n;
char ***results;
int resultCount;

int isSafe(int row, int col) {
    for (int r = 0; r < row; r++) {
        // same column, or on a diagonal
        if (cols[r] == col || abs(cols[r] - col) == abs(r - row))
            return 0;
    }
    return 1;
}

void buildBoard(char ***results, int count) {
    results[count] = (char **)malloc(n * sizeof(char *));
    for (int r = 0; r < n; r++) {
        results[count][r] = (char *)malloc((n + 1) * sizeof(char));
        for (int c = 0; c < n; c++)
            results[count][r][c] = (cols[r] == c) ? 'Q' : '.';
        results[count][r][n] = '\0';
    }
}

void solve(int row) {
    if (row == n) {
        buildBoard(results, resultCount++);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            cols[row] = col;
            solve(row + 1);
        }
    }
}

char ***solveNQueens(int inputN, int *returnSize, int **returnColumnSizes) {
    n = inputN;
    resultCount = 0;
    // max solutions for n=9 is 352
    results = (char ***)malloc(400 * sizeof(char **));
    solve(0);
    *returnSize = resultCount;
    *returnColumnSizes = (int *)malloc(resultCount * sizeof(int));
    for (int i = 0; i < resultCount; i++)
        (*returnColumnSizes)[i] = n;
    return results;
}

int main() {
    int n = 4;
    int returnSize;
    int *columnSizes;
    char ***ans = solveNQueens(n, &returnSize, &columnSizes);
    printf("Total solutions: %d\n\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int r = 0; r < n; r++)
            printf("%s\n", ans[i][r]);
        printf("\n");
    }
    return 0;
}