#include<stdio.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColumnSizes) {

    // worst case: newInterval doesn't overlap anything, adds 1 extra
    int maxSize = intervalsSize + 1;
    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
    int count = 0;
    int i = 0;

    // phase 1: add intervals that end before newInterval starts
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    // phase 2: merge all overlapping intervals into newInterval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
        if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
        i++;
    }
    // push the merged newInterval
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = newInterval[0];
    result[count][1] = newInterval[1];
    (*returnColumnSizes)[count] = 2;
    count++;

    // phase 3: add remaining intervals
    while (i < intervalsSize) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    *returnSize = count;
    return result;
}