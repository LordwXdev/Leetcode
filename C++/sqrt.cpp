class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        long left = 1, right = x, ans = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (mid * mid <= x) {
                ans = mid;      // mid works, but maybe a bigger one works too
                left = mid + 1;
            } else {
                right = mid - 1; // mid too big, search smaller half
            }
        }

        return (int)ans;
    }
};