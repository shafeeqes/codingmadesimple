/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1
 

Constraints:

1 <= s.length <= 500
All characters of s are lower case English letters.
*/

/*
So imagine the string bcd.. there is a mismatch between b and d, right?
We can either insert a d before the b, or a 'b' after the 'd'.
If we insert a b after the d, then the first b is already matched, so then the 
problem reduces to finding the min insertions for the string 'cd', and then adding 1

If we insert a 'd' before the 'b', then the last d is matched, so problem reduces to 
finding the min insertions for 'bc', and adding 1. You can then take the minimum of 
these two options to find the overall minimum number of insertions.

Generalizing this to a dp formula gives:
min_ins[i][j] = the minimum number of insertions to make the substring from i..j a palindrome
if s[i] == s[j]: you dont need to insert anything, so it reduces to min_ins[i+1][j-1]
otherwise: based on the above reasoning, its min(1+min_ins[i+1][j], 1+min_ins[i][j-1]).

Also for a base case, if i==j (a 1 length substring), that substring is already a 
palindrome by default.

Since I am doing bottom up DP, I need to solve for the smaller length substrings 
before solving for the larger length substrings
*/

class Solution {
public:
    int minInsertions(string str) {
        int n = str.size();
        if(n==0) return 0;
        int table[n][n];
        memset(table,0,sizeof(table));
        int l,r;
        for(int len = 1; len<n; len++ ){
            for(l = 0, r=len; r<n; l++,r++){
                if(str[l]==str[r]){
                    table[l][r]= table[l+1][r-1];
                }
                else{
                    table[l][r] = min(table[l+1][r],table[l][r-1])+1;
                }
            }
        }	
        return table[0][n-1];
    }
};


