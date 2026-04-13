#include<stdio.h>

void reverse(int* nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: find first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0) {
        // Step 2: find first element larger than nums[i] from the right
        int j = numsSize - 1;
        while (nums[j] <= nums[i])
            j--;
        // Step 3: swap
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // Step 4: reverse everything after i
    reverse(nums, i + 1, numsSize - 1);
}