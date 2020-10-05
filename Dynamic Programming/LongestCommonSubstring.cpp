/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some c
haracters(can be none) deleted without changing the relative order of the remaining characters. 
(eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings
is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/
/*
Question: You are given 2 strings. Return the length of the longest subsequence that the 2 strings share.

Complexities

n = s1.length()
m = s2.length()

Time: O( nm )

We can upper bound time by the number of subproblems that we are going to solve.

Space: O( nm )

We upper bound space by the number of subproblems we will story answers to. Whether we do (n + 1)(m + 1) or (n)(m) doesn't matter asymptotically.
*/
/*
eg: aab and azb

lcs(aab,azb)
-------------
we compare a and a. same.
so answer will be 1 + lcs(ab,zb)
that is removing a from both.

lcs (ab,zb)
------------
a and z are not same
so answer will be max(lcs(a,zb) , lcs(ab,b))

lcs(a,zb)
----------
no common, max(lcs(a,b), lcs(" ",b)
both are zero. any char with empty string have zero in common

lcs(ab,b)
---------
 a not equal to b. so max(lcs(b," "),lcs(b,b))
                      = max(0,1)
                      
  this goes up so lcs(aab,azb) = + lcs(ab,zb) = 1 + max(lcs(a,zb) , lcs(ab,b)) = 1 +  max(0,1) = 2     
  
  
  dp table
  ----------
  
     " " a  z  b
 " "  0  0  0  0
 a    0  1  1  1
 a    0  1  1  1
 b    0  1  1  2
*/


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = max(n1,n2);
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        //the first row and first column will be zero because we are considering empty strings on both
        for(int i = 1; i< n1+1; i++){
            for(int j = 1; j< n2+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
