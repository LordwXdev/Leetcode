#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // phase 1: add all intervals that end before newInterval starts
        // no overlap, they sit completely to the left
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // phase 2: merge all overlapping intervals into newInterval
        // overlap condition: current start <= newInterval end
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval); // push the fully merged interval

        // phase 3: add remaining intervals (sit completely to the right)
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};