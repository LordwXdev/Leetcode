#include <stdlib.h>
#include <string.h>

void backtrack(char* current, int pos, int open, int close, int n,
               char** result, int* returnSize) {
    
    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(current, pos + 1, open + 1, close, n, result, returnSize);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(current, pos + 1, open, close + 1, n, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    // Maximum possible combinations for n <= 8 is 1430
    char** result = (char**)malloc(1430 * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    backtrack(current, 0, 0, 0, n, result, returnSize);

    free(current);
    return result;
}