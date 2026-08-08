#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<long long> dp(n, 0);
        
        // if the very first cell is blocked, no path exists at all
        dp[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // can't stand on an obstacle
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // add ways coming from the left
                }
                // if j == 0 and not obstacle, dp[j] just keeps value from row above (came from up)

                
            }
        }
        
        return (int)dp[n - 1];
    }
};