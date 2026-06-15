#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (auto& interval : intervals) {
        // if result is empty OR no overlap with last interval
        if (result.empty() || interval[0] > result.back()[1]) {
            result.push_back(interval);
        } else {
            // overlap: stretch end if the current one goes further
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);

    cout << "Output: ";
    for (auto& v : res) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;  // [[1,6],[8,10],[15,18]]

    // test case 3: unsorted input
    vector<vector<int>> intervals2 = {{4,7},{1,4}};
    res = merge(intervals2);

    cout << "Output: ";
    for (auto& v : res) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;  // [[1,7]]

    return 0;
}