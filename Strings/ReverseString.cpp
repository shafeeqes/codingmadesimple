/*
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

//See python solution. it's a piece of cake
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    stack<string> s;
	    int flag = 0;
	    string temp = "";
	    for(int i=0; i<str.size(); i++){
	        if(str[i] == '.'){
	            if(!s.empty())
	                temp += ".";
	            s.push(temp);
	            temp = "";
	            flag =1;
	        }
	        else
	        temp += str[i];
	    }
	    if(flag ==1)
	        temp += ".";
	    s.push(temp);
	    
	    while(!s.empty()){
	        cout<<s.top();
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
