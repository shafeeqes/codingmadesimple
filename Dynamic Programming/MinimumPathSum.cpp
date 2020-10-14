/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++ ){
                if(i == 0 and j == 0){
                    dp[i][j] = A[i][j];
                    continue;   
                }
                if(i == 0){
                    dp[i][j] = A[i][j] + dp[i][j-1];
                    continue;
                }
                if(j == 0){
                    dp[i][j] = A[i][j] + dp[i-1][j];
                    continue;
                }
                
                dp[i][j] = A[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
             
        return dp[n-1][m-1];
    }
};
