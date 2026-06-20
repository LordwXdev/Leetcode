// ============================================================
//  60. Permutation Sequence
//  Language: C++
// ============================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Factorial table
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        // Available digits
        vector<int> digits;
        for (int i = 1; i <= n; i++)
            digits.push_back(i);

        string result;
        k--;  // 0-indexed

        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            result += ('0' + digits[idx]);
            digits.erase(digits.begin() + idx);  // remove used digit
            k %= fact[i - 1];
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<tuple<int, int, string>> tests = {
        {3, 3, "213"},
        {4, 9, "2314"},
        {3, 1, "123"}
    };

    for (auto &[n, k, expected] : tests) {
        string res = sol.getPermutation(n, k);
        cout << "n=" << n << " k=" << k
             << " -> " << res
             << "  (expected: " << expected << ")  "
             << (res == expected ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}