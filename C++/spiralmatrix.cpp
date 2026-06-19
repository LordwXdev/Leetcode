#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (num <= n * n) {
            // go right
            for (int col = left; col <= right; col++)
                matrix[top][col] = num++;
            top++;

            // go down
            for (int row = top; row <= bottom; row++)
                matrix[row][right] = num++;
            right--;

            // go left
            for (int col = right; col >= left; col--)
                matrix[bottom][col] = num++;
            bottom--;

            // go up
            for (int row = bottom; row >= top; row--)
                matrix[row][left] = num++;
            left++;
        }

        return matrix;
    }
};

int main() {
    Solution sol;

    auto result = sol.generateMatrix(3);
    cout << "n=3: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < (int)result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < (int)result.size() - 1) cout << ",";
    }
    cout << "]\n";

    auto result2 = sol.generateMatrix(1);
    cout << "n=1: [[" << result2[0][0] << "]]\n";

    return 0;
}