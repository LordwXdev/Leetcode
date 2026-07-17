#include<iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        // skip leading sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool digitsSeen = false;
        bool dotSeen = false;

        // read digits and at most one dot
        while (i < n && (isdigit(s[i]) || s[i] == '.')) {
            if (s[i] == '.') {
                if (dotSeen) return false; // two dots, no good
                dotSeen = true;
            } else {
                digitsSeen = true;
            }
            i++;
        }

        if (!digitsSeen) return false; // need at least one digit somewhere before e

        // check for exponent part
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;

            bool expDigits = false;
            while (i < n && isdigit(s[i])) {
                expDigits = true;
                i++;
            }
            if (!expDigits) return false; // "e" with nothing after it
        }

        // if we didn't reach the end, something extra and bad is there
        return i == n;
    }
};