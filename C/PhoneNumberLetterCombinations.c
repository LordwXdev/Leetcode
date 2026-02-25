#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mapping[] = {
    "",     "",     "abc",  "def",
    "ghi",  "jkl",  "mno",  "pqrs",
    "tuv",  "wxyz"
};

void backtrack(char* digits, int index, char* current,
               char** result, int* returnSize) {
    
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    
    char* letters = mapping[digits[index] - '0'];
    
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    
    if (digits == NULL || digits[0] == '\0')
        return NULL;
    
    int len = strlen(digits);
    
    // Maximum possible combinations: 4^4 = 256
    char** result = malloc(256 * sizeof(char*));
    char* current = malloc((len + 1) * sizeof(char));
    current[len] = '\0';
    
    backtrack(digits, 0, current, result, returnSize);
    
    free(current);
    return result;
}