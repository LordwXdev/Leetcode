#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getPermutation(int n, int k) {

    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    // Available digits
    int digits[10];
    for (int i = 0; i < n; i++)
        digits[i] = i + 1;

    // Result string: n chars + null terminator
    char *result = (char *)malloc(n + 1);
    result[n] = '\0';

    k--;  // Switch to 0-indexed

    for (int i = n; i >= 1; i--) {
        // Which digit do we pick?
        int idx = k / fact[i - 1];
        result[n - i] = '0' + digits[idx];

        // Remove used digit (shift left)
        for (int j = idx; j < i - 1; j++)
            digits[j] = digits[j + 1];

        k %= fact[i - 1];
    }

    return result;
}

int main(void) {
    int tests[][2] = {{3, 3}, {4, 9}, {3, 1}};
    char *expected[] = {"213", "2314", "123"};

    for (int i = 0; i < 3; i++) {
        int n = tests[i][0], k = tests[i][1];
        char *res = getPermutation(n, k);
        printf("n=%-2d k=%-3d -> %-6s  (expected: %s) %s\n",
               n, k, res, expected[i],
               strcmp(res, expected[i]) == 0 ? "PASS" : "FAIL");
        free(res);
    }
    return 0;
}