/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        if(r == 1 and c == 1){
            if(grid[0][0] == 0)
                return 1;
            else
                return 0;
        }
        int dp[r][c];
        memset(dp,0,sizeof(dp));
        
        //if start is not an obstacle
        if(grid[0][0] == 0)
            dp[0][0] = 1;
        else
            return 0;
        
        for(int i = 1; i < r; i++){
            if(grid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        
        for(int j = 1; j < c; j++){
            if(grid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }
        
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                //if there is an obstacle dp =0. since we already set it to zero
                //just continue
                if(grid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[r-1][c-1];
    }
};
