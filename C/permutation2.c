#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, bool* used, int* path, int pathSize,
               int** result, int* returnSize, int** returnColumnSizes) {
    if (pathSize == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        
        used[i] = true;
        path[pathSize] = nums[i];
        
        backtrack(nums, numsSize, used, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
        
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize,
                    int** returnColumnSizes) {
    // Sort first so duplicates are adjacent
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Max possible permutations is 8! = 40320 (upper bound)
    int maxPerms = 40320;
    int** result = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));
    *returnSize = 0;
    
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    int* path = (int*)malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, used, path, 0, result, returnSize, returnColumnSizes);
    
    free(used);
    free(path);
    return result;
}