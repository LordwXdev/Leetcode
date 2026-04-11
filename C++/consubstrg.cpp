#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        // build frequency map of words
        unordered_map<string, int> wordFreq;
        for (const string& w : words)
            wordFreq[w]++;

        // try every starting index from 0 to sLen - totalLen
        for (int i = 0; i <= sLen - totalLen; i++) {
            unordered_map<string, int> seen;
            int j = 0;

            while (j < wordCount) {
                string word = s.substr(i + j * wordLen, wordLen);

                if (wordFreq.find(word) == wordFreq.end())
                    break; // word not in list at all

                seen[word]++;

                if (seen[word] > wordFreq[word])
                    break; // used this word too many times

                j++;
            }

            if (j == wordCount)
                result.push_back(i);
        }

        return result;
    }
};