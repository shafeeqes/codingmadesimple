/*.Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
â€‹Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.


Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function
maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 100
1 ≤ Matrix[i][j] ≤ 1000.*/



class Solution{
public:
    int maximumPath(int N, vector<vector<int>> A)
    {
        vector<vector<int>> dp(N,vector<int> (N,0));
        int maxsum = 0;
        if(N == 1)  return A[0][0];
        
        //for the first row max is the matrix value itself
        //cause all the paths comefrom only [row-1][c], [row-1][c-1], [row-1][c+1]
        for(int j = 0; j < N; j++){
            dp[0][j] = A[0][j];
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                int maxpossible = 0;
                //checking for bounds
                if(j-1 >= 0)
                    maxpossible = max(maxpossible,dp[i-1][j-1]);
                if(j + 1 < N)
                    maxpossible = max(maxpossible,dp[i-1][j+1]);
                maxpossible = max(maxpossible,dp[i-1][j]); 
                //adding matrix element plus maxpossible pathsum
                dp[i][j] = A[i][j] + maxpossible;
                //updating ans to max of ans and curr dp element
                maxsum = max(maxsum, dp[i][j]);
            }
        }
        return maxsum;
    }
};

