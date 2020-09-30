/*
Coins in a Line
Problem Description

There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins, Assume that you go first.

Return the maximum amount of money you can win.

NOTE:

You can assume that opponent is clever and plays optimally.


Problem Constraints
1 <= length(A) <= 500

1 <= A[i] <= 105



Input Format
The first and the only argument of input contains an integer array A.



Output Format
Return an integer representing the maximum amount of money you can win.



Example Input
Input 1:

 A = [1, 2, 3, 4]
Input 2:

 A = [5, 4, 8, 10]


Example Output
Output 1:

 6
Output 2:

 15


Example Explanation
Explanation 1:

 You      : Pick 4
 Opponent : Pick 3
 You      : Pick 2
 Opponent : Pick 1


Total money with you : 4 + 2 = 6

Explanation 2:

 You      : Pick 10
 Opponent : Pick 8
 You      : Pick 5
 Opponent : Pick 4


Total money with you : 10 + 5 = 15
*/

void solve(vector<int> A,int L, int R,vector<vector<int> > &dp){
    //Important not L = R -1
    if(abs(L-R)==1){
        dp[L][R] = max(A[L],A[R]);
    }
        
    else{
        if(dp[L+1][R-1]==-1){
            solve(A,L+1,R-1,dp);
        }
        if(dp[L+2][R]==-1){
            solve(A,L+2,R,dp);
        }
        if(dp[L][R-2]==-1){
            solve(A,L,R-2,dp);
        }
        if(dp[L+1][R-1]==-1){
            solve(A,L+1,R-1,dp);
        }
        int left = A[L] + min(dp[L+1][R-1],dp[L+2][R]);
        int right = A[R] + min(dp[L][R-2],dp[L+1][R-1]);
        dp[L][R] = max(left,right);
    } 
    
}
int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size();
    vector<vector<int> > dp (n, vector<int>(n,-1));
    solve(A,0,n-1,dp);
    return dp[0][n-1]; 
}


//same but function with return value instead of void

int helper(vector<int> &A,vector<vector<int>> &dp, int left, int right){
    if(left>=right){
        return 0;
    }
    if(abs(right-left) == 1){
        dp[left][right] = max(A[left],A[right]);
        return dp[left][right];
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    else{
        int val1 = A[left] + min(helper(A,dp,left+1,right-1),helper(A,dp,left+2,right));
        int val2 = A[right] + min(helper(A,dp,left,right-2),helper(A,dp,left+1,right-1));
        dp[left][right] = max(val1,val2);
        return dp[left][right];
    } 
}


int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(A,dp,0,n-1);
}
