#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1 or >= string length, no zigzag needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Create a vector of strings, one for each row
        vector<string> rows(numRows);
        
        int currentRow = 0;
        bool goingDown = false;
        
        // Traverse through each character
        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction at the first and last row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to next row
            currentRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows
        string result;
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};