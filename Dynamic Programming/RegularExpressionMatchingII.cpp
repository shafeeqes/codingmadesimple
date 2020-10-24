/*
Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return 0 or 1:
    => 0 : If the patterns do not match.
    => 1 : If the patterns match.
Constraints:

1 <= length(A), length(B) <= 9e4
Examples :

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

Input 5:
    A = "aa"
    B = "a*"

Output 5:
    1

Input 6:
    A = "ab"
    B = "?*"

Output 6:
    1

Input 7:
    A = "aab"
    B = "c*a*b"

Output 7:
    0
    */
    
    //see regular expression matching 1 for full explanation
    
    
 int Solution::isMatch(const string text, const string pattern) {
    
    int r = text.size();
    int c = pattern.size();
    
    bool dp[r+1][c+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    
    for(int i = 1; i < c+1; i++){
        //if pattern has * it can match empty string provided there are not values before
        if(pattern[i-1]== '*')
            dp[0][i] = dp[0][i-1];
    }
    
    for(int i = 1; i < r+1; i++){
        for(int j = 1; j < c +1; j++){
            if(pattern[j-1] == text[i-1] or pattern[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
              //if pattern is '*' which means either the pattern is an empty character
              //so we check dp[i][j-1] that is pattern till the prev char  or * can match any 
              // sequence in text so we take dp[i-1][j] which is the truth value till the prev text
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[r][c] ? 1:0;
    
}
   
