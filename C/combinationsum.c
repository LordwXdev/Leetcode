#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* current, int currentSize,
               int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        // Found a valid combination, copy it
        result[*returnSize] = (int*)malloc(sizeof(int) * currentSize);
        memcpy(result[*returnSize], current, sizeof(int) * currentSize);
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }
    if (target < 0) return;

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) continue; // small optimization
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i,
                  current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 150);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
    *returnSize = 0;

    int* current = (int*)malloc(sizeof(int) * target); // worst case depth
    backtrack(candidates, candidatesSize, target, 0, current, 0,
              result, returnSize, returnColumnSizes);
    free(current);
    return result;
}