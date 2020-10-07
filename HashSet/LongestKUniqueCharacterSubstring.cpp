/*

Longest K unique characters substring 
Easy Accuracy: 44.46% Submissions: 10420 Points: 2
Given a string you need to print the size of the longest possible substring that has exactly k unique characters. If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.


Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. Each test case contains two lines . The first line of each test case contains a string s and the next line conatains an integer k.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=k<=10

Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4
*/


#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int solution(string s,int k){
    
    string temp = "";
    int maxsize = -1;
    int count = 0;
    
    int a[26] = {0};
    for(int i = 0; i< s.size(); i++){
        if(a[s[i]-'a']==0)
            count++;
        a[s[i]-'a']++;
    }
    if(count<k)
        return -1;
    count = 0;    
    memset(a,0,sizeof(a));    
    string save;
    for(int i = 0; i< s.size(); i++){
        temp += s[i];
        if(a[s[i]-'a']==0)
            count++;
        a[s[i]-'a']++;
        if(count>k){
            while(count>k){
                a[temp[0]-'a']--;
                if(a[temp[0]-'a']==0){
                    count--;
                }
		    //a char queue might work better
                temp = temp.substr(1,temp.size()-1);
            }
        }
        int n = temp.size();
        if(n> maxsize){
            maxsize = n;
            save = temp;
        }
    }
    //cout<<save;
    return maxsize;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int k;
	    cin>>k;
	    cout<<solution(s,k)<<endl;
	}
	return 0;
}
