/*
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.



Problem Constraints
1 <= |A| <= 100



Input Format
The first and the only argument of input contains a string A.



Output Format
Return an integer, 0 or 1:

    => 0 : False
    => 1 : True


Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "ab" is repeated.
Explanation 2:

 There is no repeating subsequence
 */
 
 //This can be done my making a minor change to the Longest Common subsequence.
 // by adding an  i != j condition when same character is faced with.
 //this makes sure that the character repeats elsewhere.
 
 int Solution::anytwo(string A) {
    int n = A.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
   
    for(int i = 1; i< n+1; i++){
        for(int j = 1; j< n+1; j++){
            if(A[i-1] == A[j-1] and i!=j){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n] >=2 ? 1:0;
}
