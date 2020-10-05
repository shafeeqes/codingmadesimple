/*
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, 
first of which contains 2 space separated integers N and M denoting the size of string X and Y 
strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.
*/
//Read longest common subsequence.

int solution(string s1,string s2){
    
    int n1 = s1.size();
    int n2 = s2.size();
    
    int dp[n1+1][n2+1];
    memset(dp,0,sizeof(dp));
    
    int ans = 0;
    //the first row and first column will be zero because 
    //we are considering empty strings on both
    for(int i = 1; i< n1+1; i++){
        for(int j = 1; j< n2+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }else{
              //not same, resets progress to zero
                dp[i][j] = 0;
            }
        }    
    }
    return ans;
}
