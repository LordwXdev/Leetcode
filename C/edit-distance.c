#include<stdio.h>

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);

    int** dp = malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int replace = dp[i - 1][j - 1];
                int del = dp[i - 1][j];
                int insert = dp[i][j - 1];
                int minVal = replace;
                if (del < minVal) minVal = del;
                if (insert < minVal) minVal = insert;
                dp[i][j] = 1 + minVal;
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);

    return result;
}