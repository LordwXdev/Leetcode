#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, current, used, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<int>& current, 
                   vector<bool>& used, vector<vector<int>>& result) {
        // Base case: we've picked all numbers
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try each unused number at this position
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // Choose
            current.push_back(nums[i]);
            used[i] = true;
            
            // Explore
            backtrack(nums, current, used, result);
            
            // Un-choose (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
};