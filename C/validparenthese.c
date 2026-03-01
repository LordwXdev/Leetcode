#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool isValid(char* s) {
    int len = strlen(s);
    char *stack = malloc(len);
    int top = -1;
    
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[++top] = s[i];
        else {
            if (top == -1) { free(stack); return false; }
            char c = stack[top--];
            if ((s[i] == ')' && c != '(') ||
                (s[i] == '}' && c != '{') ||
                (s[i] == ']' && c != '[')) {
                free(stack); return false;
            }
        }
    }
    free(stack);
    return top == -1;
}