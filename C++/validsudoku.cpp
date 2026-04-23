#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 arrays to track rows, columns, and boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1'; // convert '1'-'9' → 0-8
                int boxIndex = (i / 3) * 3 + (j / 3);

                // check if already seen
                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // mark as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};