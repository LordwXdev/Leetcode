#include<iostream>
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 0; j < s.size(); j++) {
                while (j + 1 < s.size() && s[j] == s[j + 1]) {
                    count++;
                    j++;
                }

                temp += to_string(count);
                temp += s[j];
                count = 1;
            }

            s = temp;
        }

        return s;
    }
};