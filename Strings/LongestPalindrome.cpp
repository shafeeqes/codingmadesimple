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

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int expand(string s, int left,int right){
    if(s.size()==0 or left>right)
        return 0;
    while(s[left] == s[right] and left>=0 and right<s.size()){
        left--;
        right++;
    }
    return right-left-1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int n = str.size();
	    int flag = 0;
	    int start = 0, end = 0;
	    for(int i=0; i<n; i++){
	        int len1 = expand(str,i,i);
	        int len2 = expand(str,i,i+1);
	        int len = max(len1,len2);
	        if (len > (end-start)){
	            start = i - ((len-1)/2);
	            end = i + (len/2);
	            if(len>1)
	                flag = 1;
	        }
	   }
	   if (flag == 0){
	       cout<<str.substr(0,1);
	       break;
	   }
	   string ans = str.substr(start,end-start+1);
	   cout<<ans<<endl;
	}
	return 0;
}
