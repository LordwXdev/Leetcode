#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

typedef struct Node {
    char* key;          // sorted string
    char** strings;     // original strings in this group
    int size;
    int capacity;
    struct Node* next;
} Node;

// Simple string hash
unsigned long hashStr(const char* s) {
    unsigned long h = 5381;
    int c;
    while ((c = *s++)) h = ((h << 5) + h) + c;
    return h % HASH_SIZE;
}

// qsort comparator for chars
int cmpChar(const void* a, const void* b) {
    return *(const char*)a - *(const char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node** table = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    Node** groupList = (Node**)malloc(strsSize * sizeof(Node*));
    int groupCount = 0;
    
    for (int i = 0; i < strsSize; i++) {
        // Make sorted key
        int len = strlen(strs[i]);
        char* key = (char*)malloc(len + 1);
        memcpy(key, strs[i], len + 1);
        qsort(key, len, sizeof(char), cmpChar);
        
        // Look it up in the hash table
        unsigned long h = hashStr(key);
        Node* cur = table[h];
        while (cur && strcmp(cur->key, key) != 0) cur = cur->next;
        
        if (cur) {
            // Group exists, append the original string
            free(key);
            if (cur->size == cur->capacity) {
                cur->capacity *= 2;
                cur->strings = (char**)realloc(cur->strings, cur->capacity * sizeof(char*));
            }
            cur->strings[cur->size++] = strs[i];
        } else {
            // New group
            Node* node = (Node*)malloc(sizeof(Node));
            node->key = key;
            node->capacity = 4;
            node->size = 0;
            node->strings = (char**)malloc(node->capacity * sizeof(char*));
            node->strings[node->size++] = strs[i];
            node->next = table[h];
            table[h] = node;
            groupList[groupCount++] = node;
        }
    }
    
    // Build the result
    char*** result = (char***)malloc(groupCount * sizeof(char**));
    *returnColumnSizes = (int*)malloc(groupCount * sizeof(int));
    
    for (int i = 0; i < groupCount; i++) {
        Node* n = groupList[i];
        result[i] = (char**)malloc(n->size * sizeof(char*));
        for (int j = 0; j < n->size; j++) {
            result[i][j] = n->strings[j];
        }
        (*returnColumnSizes)[i] = n->size;
        
        free(n->key);
        free(n->strings);
        free(n);
    }
    
    free(table);
    free(groupList);
    *returnSize = groupCount;
    return result;
}