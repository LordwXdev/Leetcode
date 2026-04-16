#include <climits>
#include <cstdlib>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int result = 0;

        while (dvd >= dvs) {
            long temp = dvs;
            int multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};