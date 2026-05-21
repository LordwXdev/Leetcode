#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // avoid overflow

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        while (N > 0) {
            // if exponent is odd
            if (N % 2 == 1) {
                result *= x;
            }

            x *= x;
            N /= 2;
        }

        return result;
    }
};

/*int main() {
    Solution s;

    cout << s.myPow(2.0, 10) << endl; // 1024
    cout << s.myPow(2.1, 3) << endl;  // 9.261
    cout << s.myPow(2.0, -2) << endl; // 0.25

    return 0;
}*/