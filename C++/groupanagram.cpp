#include<iostream>
#include<vector>
#include <unordered_map>


using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            int count[26] = {0};
            for (char c : s) count[c - 'a']++;
            
            // Build key like "1#0#2#0#..." so counts don't collide
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]);
                key += '#';
            }
            
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& [_, group] : groups) {
            result.push_back(move(group));
        }
        return result;
    }
};