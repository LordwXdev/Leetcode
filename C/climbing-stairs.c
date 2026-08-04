#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1; // ways to reach step 1
    int prev1 = 2; // ways to reach step 2
    int curr;

    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    printf("%d\n", climbStairs(2)); // 2
    printf("%d\n", climbStairs(3)); // 3
    return 0;
}