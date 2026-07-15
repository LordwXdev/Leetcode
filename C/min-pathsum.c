#include<stdio.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                grid[i][j] += grid[i][j - 1];       // first row: only from left
            } else if (j == 0) {
                grid[i][j] += grid[i - 1][j];       // first column: only from above
            } else {
                int fromTop = grid[i - 1][j];
                int fromLeft = grid[i][j - 1];
                grid[i][j] += (fromTop < fromLeft) ? fromTop : fromLeft;
            }
        }
    }

    return grid[m - 1][n - 1];
}