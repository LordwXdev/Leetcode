#include<stdio.h>

char* simplifyPath(char* path) {
    int n = strlen(path);
    char** stack = malloc(n * sizeof(char*));
    int top = 0;

    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            // do nothing
        } else if (strcmp(token, "..") == 0) {
            if (top > 0) top--;
        } else {
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }

    char* result = malloc(n + 2); // enough room
    result[0] = '\0';

    if (top == 0) {
        strcpy(result, "/");
    } else {
        for (int i = 0; i < top; i++) {
            strcat(result, "/");
            strcat(result, stack[i]);
        }
    }

    free(stack);
    return result;
}