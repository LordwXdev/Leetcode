#include<iostream>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying by 10
            // INT_MAX = 2147483647, INT_MIN = -2147483648
            // If result > INT_MAX/10, then result*10 will overflow
            // If result == INT_MAX/10, then result*10+digit might overflow
            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            result = result * 10 + digit;
        }
        
        return result;
    }
};
