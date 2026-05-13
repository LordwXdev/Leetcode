#include<stdio.h>
#include<stdbool.h>

void backtrack(int* nums, int numsSize, int* current, int currentSize,
               bool* used, int** result, int* returnSize) {
    // Base case: full permutation built
    if (currentSize == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        
        // Choose
        current[currentSize] = nums[i];
        used[i] = true;
        
        // Explore
        backtrack(nums, numsSize, current, currentSize + 1, used, result, returnSize);
        
        // Un-choose
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Total permutations = n! (max is 6! = 720)
    int total = 1;
    for (int i = 1; i <= numsSize; i++) total *= i;
    
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    int* current = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    *returnSize = 0;
    
    backtrack(nums, numsSize, current, 0, used, result, returnSize);
    
    free(current);
    free(used);
    return result;
}