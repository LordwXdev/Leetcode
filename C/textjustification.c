#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    // worst case, every word is its own line
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int resultCount = 0;

    int i = 0;
    while (i < wordsSize) {
        int j = i;
        int lineLen = 0;

        // pack as many words as fit
        while (j < wordsSize && lineLen + (int)strlen(words[j]) + (j - i) <= maxWidth) {
            lineLen += strlen(words[j]);
            j++;
        }

        int numWords = j - i;
        int totalSpaces = maxWidth - lineLen;
        int isLastLine = (j == wordsSize);

        char* line = (char*)malloc(sizeof(char) * (maxWidth + 1));
        int pos = 0;

        if (numWords == 1 || isLastLine) {
            // left justify
            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;
                if (k != j - 1) {
                    line[pos++] = ' ';
                }
            }
            while (pos < maxWidth) {
                line[pos++] = ' ';
            }
        } else {
            int gaps = numWords - 1;
            int spaceEach = totalSpaces / gaps;
            int extra = totalSpaces % gaps;

            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;

                if (k != j - 1) {
                    int spacesToAdd = spaceEach + ((k - i) < extra ? 1 : 0);
                    for (int s = 0; s < spacesToAdd; s++) {
                        line[pos++] = ' ';
                    }
                }
            }
        }

        line[maxWidth] = '\0';
        result[resultCount++] = line;
        i = j;
    }

    *returnSize = resultCount;
    return result;
}