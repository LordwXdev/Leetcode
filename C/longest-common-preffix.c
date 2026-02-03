#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }

    int prefixLen = strlen(strs[0]);

    for (int i = 0; i < prefixLen; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (i >= (int)strlen(strs[j]) || strs[j][i] != strs[0][i]) {
                prefixLen = i;
                goto done;
            }
        }
    }

done:
    char* result = malloc(prefixLen + 1);
    strncpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return result;
}