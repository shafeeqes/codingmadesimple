/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
/*

Input: "Saturday" and "Sundays"
Output: 4

Why:
In: "Saturday"
1.) Delete the first 'a' ("Sturday")
2.) Delete the first 't' ("Surday")
3.) Replace 'r' with 'n' ("Sunday")
4.) Insert an 's' at the end ("Sundays")
Out: "Sundays"

Our 3 Operations To Fix Character Mismatch:
- Insert
- Delete
- Replacement
*/
/*

the columns are made of the empty set and letters of the initial word
the rows are made of the empty set and letters of the final word

from empty set to reach 1 letter, no of opns is 1, 2 letters, 2 and so on.
similarly from 1 letter initial to empty set, no of ops(deletion) is 1. from 2 letters
2 and so on.

so the first row and column will be filled with its index itself.

now we start comparing. 

LD( horse, rose)

if we see the last letter, e is same.
so this will be same as the problem  LD(hors, ros)

again this will be same as LD(hor,ro)

so if letters are same dp[i][j] = dp[i-1][j-1]

if letters are not same we have 3 options.

hor, ro . if we are replacing ,then it doesnt matter whatever we have here, it will be same as LD(ho,r) + 1

if we are inserting, then it will be same as LD(hor, r) + 1, we are inserting a new character at the place of the last character

if we are delting it will be same as LD(ho,ro) + 1, we are deleting the character which is not matching so we have "ho" and ro stays same, 
so same row, col - 1

                .
replace         .   insert
dp[i-1]j-1]     .   dp[i-1][j]
                .
.....................................
                .
 delete         .   dp[i][j] = 1 + min(insert,delete,replace)
 dp[i][j-1]     .   
                .



*/


class Solution {
public:
    int minDistance(string initialw, string finalw) {
        
        int c = initialw.size();
        int r = finalw.size();
        
        int dp[r+1][c+1];
        
        for(int i = 0; i < c+1; i++){
            dp[0][i] = i;
        }
        for(int i = 0; i < r+1; i++){
            dp[i][0] = i;
        }
        
        for(int i = 1; i < r + 1; i++){
            for(int j = 1; j < c + 1; j++){
                if(initialw[j-1] == finalw[i-1]){
                    //same as the subproblem without these letters
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else{
                    //min of replace, insert, delete operations
                    dp[i][j] =  1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[r][c];
    }
};
