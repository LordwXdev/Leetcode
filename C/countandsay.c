#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    char* s = (char*)malloc(5000);
    strcpy(s, "1");

    for (int i = 2; i <= n; i++) {
        char* temp = (char*)malloc(5000);
        temp[0] = '\0';

        int len = strlen(s);
        int count = 1;

        for (int j = 0; j < len; j++) {
            while (j + 1 < len && s[j] == s[j + 1]) {
                count++;
                j++;
            }

            char buffer[20];
            sprintf(buffer, "%d%c", count, s[j]);
            strcat(temp, buffer);

            count = 1;
        }

        free(s);
        s = temp;
    }

    return s;
}