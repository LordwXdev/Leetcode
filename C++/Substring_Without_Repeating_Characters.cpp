#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If character is already in the window, move left pointer
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }
            
            // Update the character's latest position
            charIndex[currentChar] = right;
            
            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};