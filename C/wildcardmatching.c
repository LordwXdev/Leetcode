#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    
    // Allocate 2D dp array
    bool** dp = (bool**)malloc((m + 1) * sizeof(bool*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (bool*)calloc(n + 1, sizeof(bool));
    }
    
    // Empty string matches empty pattern
    dp[0][0] = true;
    
    // Empty string can match pattern of only '*'
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                // '*' matches empty OR extends match
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    
    bool result = dp[m][n];
    
    // Free memory
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    
    return result;
}