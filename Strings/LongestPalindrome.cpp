/*
Given a string S, find the longest palindromic substring in S. Substring of 
string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string 
which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist
of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0)
            return "";
        string ans;
        int start = 0, end = 0;
        int len = 1;
        for(int i = 0; i< n; i++){
            int len1 = expand(s, i, i);
	        int len2 = expand(s, i, i+1);
	        int len = max(len1, len2);
            
            //if current palindrome is longer than the previously saved
            if(len > (end - start)){
                start = i - ((len-1)/2);
                end  = i + (len/2);
            }
        }
        
        return s.substr(start,end-start+1);
    }
    
    int expand(string s, int left, int right){
        if(left > right){
            return 0;
        }
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            left --;
            right ++;
        }
        return right-left-1;
    }
};
