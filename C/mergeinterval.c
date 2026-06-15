#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];  // sort by start time
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // sort intervals by start value
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // worst case: no merges happen, so we need intervalsSize slots
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int count = 0;

    // put the first interval in as-is
    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    count = 1;

    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[count - 1];  // last merged interval
        int curStart = intervals[i][0];
        int curEnd   = intervals[i][1];

        if (curStart <= last[1]) {
            // overlap: just stretch the end if needed
            if (curEnd > last[1]) {
                last[1] = curEnd;
            }
        } else {
            // no overlap: add it as a new interval
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = curStart;
            result[count][1] = curEnd;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return result;
}

// quick test
int main() {
    int a[] = {1,3}, b[] = {2,6}, c[] = {8,10}, d[] = {15,18};
    int* intervals[] = {a, b, c, d};
    int colSizes[] = {2,2,2,2};
    int returnSize;
    int* returnColSizes;

    int** result = merge(intervals, 4, colSizes, &returnSize, &returnColSizes);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d] ", result[i][0], result[i][1]);
        free(result[i]);
    }
    printf("\n");

    free(result);
    free(returnColSizes);
    return 0;
}