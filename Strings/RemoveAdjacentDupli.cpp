/*
Given a string s, recursively remove adjacent duplicate characters from the string s.
The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. 
Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd
aaaaaa

Output:
gksforgk
acac
    (empty string)
*/



using namespace std;
#include<bits/stdc++.h>

string solution(string s){
    
    string result = "";
    int n = s.size();
    int i = 0;
    while(s[i]){
        if(s[i]!=s[i+1])
            result += s[i];
        if(s[i+1] and s[i] == s[i+1]){
            while(s[i+1] and s[i]==s[i+1]){
                i++;
            }
        }
        i++;
    }
    return result;
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string A;
	    cin>>A;
	    bool flag = true;
	    string temp = solution(A);
	    string ans;
	    while(flag = true){
	        ans = solution(temp);
	        if(ans == temp){
	           flag = false;
	           break;
	        }
	        else temp = ans;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
