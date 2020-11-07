/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
    -*/

class Solution {
public:
    int numDistinct(string start, string target) {
        int r = target.size();
        int c = start.size();

        int dp[r+1][c+1];
        memset(dp,0,sizeof(dp));

        //with empty string as start you cannot make any target
        //so first column is zero
        for(int i = 0; i < r+1; i++){
            dp[i][0] = 0;
        }

        //with empty string as target, for any source you can make target in one way
        //so first row is 1

        for(int i = 0; i < c+1; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i < r+1; i++){
            for(int j = 1; j < c+1; j++){
                //if the current start char is not equal to target char
                //then the ans will be same as without this start char
                if(start[j-1] != target[i-1]){
                    dp[i][j] = dp[i][j-1];
                }
                //if the current source and target char are same, then the total no of ways
                //will be the no of ways in which the current target could have been made without
                // the current source + the no of ways in which the previous target has been made
                // from previous source, ie. the diagonally previous element
                else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
        }
        return dp[r][c];
    }
};
