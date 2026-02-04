#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    if (s == NULL || s[0] == '\0') {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    int n = strlen(s);
    if (n == 1) {
        char* result = (char*)malloc(2);
        strcpy(result, s);
        return result;
    }
    
    // Allocate DP table
    bool** dp = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        dp[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    int start = 0, maxLength = 1;
    
    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    // Check for two-character palindromes
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    
    // Check for palindromes of length 3 and more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }
    
    // Free DP table
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    // Create result string
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    
    return result;
}