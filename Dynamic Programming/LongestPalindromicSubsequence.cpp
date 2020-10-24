/*
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
1 <= |A| <= 1005



Input Format
First and only argument is an string A.



Output Format
Return a integer denoting the length of longest palindromic subsequence in A.



Example Input
Input 1:

 A = "bebeeed"


Example Output
Output 1:

 4


Example Explanation
Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4
 */
 
 int Solution::solve(string A) {
    
    int n = A.size();
    
    int dp[n][n];
    
    //All the diagonal elements  = 1;
    // ie, if there was only a single letter
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;
    
    for(int len = 2; len <= n; len ++){
        for(int i = 0; i < n-len+1; i++){
            int j = i + len - 1;
            
            //if the length is two and the end characters are same
            if(len == 2 and A[i] == A[j]){
                dp[i][j] = 2;
            }
            //otherwise if len>2, same end characters add two to the existing result
            // i+1, j-1 is the diagonally down value
            else if(A[i] == A[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
              //else maximum of the bottom value or left value
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
            
        }
    }
    //first row last value will be the ans
    return dp[0][n-1];
    
}
