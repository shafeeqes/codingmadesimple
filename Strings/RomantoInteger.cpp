/*
Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3
*/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int value(char a){
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;    
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

int romantointeger(string s){
    int ans = 0;
    int n = s.size();
    if(n<1)
        return 0;
    
    for(int i=0; i<n;i++){
        int curr = value(s[i]);
        if(i+1 <n){
            int next = value(s[i+1]);
            if(curr>=next){
                ans += curr;
            }
            else{
                ans += next - curr;
                i++;
            }
        }
        else{
            ans+= curr;
        }
    }
    return ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<romantointeger(s);
	    cout<<endl;
	}
	return 0;
}
