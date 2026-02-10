#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    
    // Step 1: Skip leading whitespace
    while (s[i] == ' ') i++;
    
    // Step 2: Determine sign
    int sign = 1;
    if (s[i] == '-') { sign = -1; i++; }
    else if (s[i] == '+') { i++; }
    
    // Step 3 & 4: Read digits and clamp
    long result = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i++] - '0');
        // Early clamp to avoid overflow in 'result' itself
        if (result * sign <= INT_MIN) return INT_MIN;
        if (result * sign >= INT_MAX) return INT_MAX;
    }
    
    return (int)(result * sign);
}