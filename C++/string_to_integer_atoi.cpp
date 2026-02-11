#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        const int n = s.size();

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Step 2: Determine sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        // Step 3 & 4: Read digits and clamp
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            // Early clamp to avoid overflow in 'result' itself
            if (result * sign <= INT_MIN) return INT_MIN;
            if (result * sign >= INT_MAX) return INT_MAX;
        }

        return static_cast<int>(result * sign);
    }
};