#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i, temp;

    for (i = 0; i < numsSize; i++) {
        while (nums[i] > 0 &&
               nums[i] <= numsSize &&
               nums[nums[i] - 1] != nums[i]) {
            
            temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return numsSize + 1;
}