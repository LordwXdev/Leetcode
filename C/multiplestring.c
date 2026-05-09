#include<stdio.h>

char* multiply(char* num1, char* num2) {
    // Handle the zero case early
    if (num1[0] == '0' || num2[0] == '0') {
        char* zero = (char*)malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }
    
    int m = strlen(num1);
    int n = strlen(num2);
    int total = m + n;
    
    // Allocate and zero out the result array
    int* result = (int*)calloc(total, sizeof(int));
    
    // Multiply each digit pair
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];
            
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    
    // Convert to string, skipping leading zeros
    char* ans = (char*)malloc(total + 1);
    int idx = 0;
    int started = 0;
    
    for (int i = 0; i < total; i++) {
        if (result[i] != 0) started = 1;
        if (started) {
            ans[idx++] = result[i] + '0';
        }
    }
    
    ans[idx] = '\0';
    free(result);
    
    return ans;
}