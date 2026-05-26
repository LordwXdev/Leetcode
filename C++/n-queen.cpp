#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> cols(n, -1); // cols[row] = column of queen in that row
        solve(0, n, cols, results);
        return results;
    }

private:
    void solve(int row, int n, vector<int>& cols, vector<vector<string>>& results) {
        if (row == n) {
            results.push_back(buildBoard(n, cols));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, cols)) {
                cols[row] = col;
                solve(row + 1, n, cols, results);
                cols[row] = -1; // backtrack
            }
        }
    }

    bool isSafe(int row, int col, vector<int>& cols) {
        for (int r = 0; r < row; r++) {
            // same column or on a diagonal
            if (cols[r] == col || abs(cols[r] - col) == abs(r - row))
                return false;
        }
        return true;
    }

    vector<string> buildBoard(int n, vector<int>& cols) {
        vector<string> board(n, string(n, '.'));
        for (int r = 0; r < n; r++)
            board[r][cols[r]] = 'Q';
        return board;
    }
};

int main() {
    Solution sol;
    int n = 4;
    auto ans = sol.solveNQueens(n);
    cout << "Total solutions: " << ans.size() << "\n\n";
    for (auto& board : ans) {
        for (auto& row : board)
            cout << row << "\n";
        cout << "\n";
    }
    return 0;
}