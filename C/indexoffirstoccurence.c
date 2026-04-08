#include<stdio.h>

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    for (int i = 0; i <= hLen - nLen; i++) {
        if (strncmp(haystack + i, needle, nLen) == 0)
            return i;
    }
    return -1;
}