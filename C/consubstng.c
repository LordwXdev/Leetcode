#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[31];
    int count;
} Entry;

int findEntry(Entry* table, int size, const char* key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i].key, key) == 0)
            return i;
    }
    return -1;
}

void setEntry(Entry* table, int* size, const char* key, int count) {
    int idx = findEntry(table, *size, key);
    if (idx != -1) {
        table[idx].count = count;
    } else {
        strcpy(table[*size].key, key);
        table[*size].count = count;
        (*size)++;
    }
}

int getCount(Entry* table, int size, const char* key) {
    int idx = findEntry(table, size, key);
    return idx != -1 ? table[idx].count : 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || wordsSize == 0) return NULL;

    int wordLen = (int)strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int sLen = (int)strlen(s);

    if (sLen < totalLen) return NULL;

    int* result = (int*)malloc(sLen * sizeof(int));

    Entry* wordFreq = (Entry*)calloc(wordsSize + 1, sizeof(Entry));
    int freqSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        int cur = getCount(wordFreq, freqSize, words[i]);
        setEntry(wordFreq, &freqSize, words[i], cur + 1);
    }

    char word[31];

    for (int i = 0; i <= sLen - totalLen; i++) {
        Entry* seen = (Entry*)calloc(wordsSize + 1, sizeof(Entry));
        int seenSize = 0;
        int j = 0;

        while (j < wordsSize) {
            strncpy(word, s + i + j * wordLen, wordLen);
            word[wordLen] = '\0';

            if (getCount(wordFreq, freqSize, word) == 0)
                break;

            int cur = getCount(seen, seenSize, word);
            setEntry(seen, &seenSize, word, cur + 1);

            if (getCount(seen, seenSize, word) > getCount(wordFreq, freqSize, word))
                break;

            j++;
        }

        if (j == wordsSize)
            result[(*returnSize)++] = i;

        free(seen);
    }

    free(wordFreq);
    return result;
}