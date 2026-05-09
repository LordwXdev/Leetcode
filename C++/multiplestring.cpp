#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        
        // Multiply from right to left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;      // carry position
                int p2 = i + j + 1;  // current position
                int sum = mul + result[p2];
                
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        // Build the string, skipping leading zeros
        string ans;
        for (int digit : result) {
            if (!(ans.empty() && digit == 0)) {
                ans.push_back(digit + '0');
            }
        }
        
        return ans.empty() ? "0" : ans;
    }
};