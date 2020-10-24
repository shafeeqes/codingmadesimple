/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isMatch(const string text, const string pattern) {
    
    int r = text.size();
    int c = pattern.size();
    
    bool dp[r+1][c+1];
    memset(dp,false,sizeof(dp));
    
    dp[0][0] = true;
    //Deals with patterns like a* or a*b* or a*b*c*
    //this means the text can have zero occurence of a, zero occurence
    //of b and so on, so it can match with empty text.
    //so we set it to true (NB: there should not be any other char in between)
    
    for (int i = 1; i < c+1; i++) {
        if (pattern[i-1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }
        
    for(int i = 1; i < r+1; i++){
        for(int j = 1; j < c +1; j++){
            //if the pattern matches then it is same as the previous
            // problem without either of these char
            if(pattern[j-1] == text[i-1] or pattern[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
                //skip the previous char of * and check if it matches
                //(since zero occurance of the prev char of * is also allowed)
                dp[i][j] = dp[i][j-2];
                //if the char before *(* is j-1th) in the pattern(j-2) is '.' or 
                //the char is equal to current text char then we  can just neglect this
                // char in the text and take value from one row above which is the
                //text without this char
                if(pattern[j-2] == '.' or pattern[j-2] == text[i-1]){
                    dp[i][j] |= dp[i-1][j];
                    //we take logical OR
                }
            }
            //if none of the above conditions, it just means the two char
            //are different. so set false
            else{
                dp[i][j] = false;
            }
            
        }
    }
    
    return dp[r][c];
    
}
