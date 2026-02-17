#include<stdio.h>


int getValue(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int romanToInt(char* s) {
    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int value = getValue(s[i]);

        if (s[i + 1] != '\0' && value < getValue(s[i + 1])) {
            total -= value;
        } else {
            total += value;
        }

        i++;
    }

    return total;
}
