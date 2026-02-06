#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    
    // Edge case: if numRows is 1 or >= string length, no zigzag needed
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }
    
    // Allocate memory for each row
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSizes = (int*)calloc(numRows, sizeof(int));
    int* rowCapacities = (int*)malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        rowCapacities[i] = len; // Allocate enough space
        rows[i] = (char*)malloc(rowCapacities[i] * sizeof(char));
        rowSizes[i] = 0;
    }
    
    int currentRow = 0;
    int goingDown = 0; // 0 = going up, 1 = going down
    
    // Traverse through each character
    for (int i = 0; i < len; i++) {
        rows[currentRow][rowSizes[currentRow]++] = s[i];
        
        // Change direction at the first and last row
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        
        // Move to next row
        currentRow += goingDown ? 1 : -1;
    }
    
    // Concatenate all rows
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            result[pos++] = rows[i][j];
        }
        free(rows[i]);
    }
    result[pos] = '\0';
    
    free(rows);
    free(rowSizes);
    free(rowCapacities);
    
    return result;
}