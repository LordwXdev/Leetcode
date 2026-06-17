#include<stdio.h>

int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;
    int length = 0;

    // skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // count the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}