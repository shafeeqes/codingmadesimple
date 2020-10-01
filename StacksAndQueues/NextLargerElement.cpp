/*
Given an array A of size N having distinct elements, the task is to find the next 
greater element for each element of the array in order of their appearance in the 
array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases
.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array 
element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1
*/


#include <iostream>
using namespace std;
#include<bits/stdc++.h>

vector<long int> nextLargerElement(vector<long int> &A){
    int n = A.size();
    vector<long int> ans(n,-1);
    stack<long int> s;
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and A[i]>= s.top())
            s.pop();
        if(!s.empty()){
            ans[i] = s.top();
        }
        s.push(A[i]);    
    }
    return ans;
}
vector<long int> altsolution(vector<long int> &A){
    int n = A.size();
    vector<long int> ans(n,-1);
    if (n<1) return ans;
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while (!s.empty() && A[s.top()] < A[i]){
            ans[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    vector<long int> A;
	    for(int i=0; i<N; i++){
	        long int temp;
	        cin>>temp;
	        A.push_back(temp);
	    }
	    //vector<long int> ans = nextLargerElement(A);
	    vector<long int> ans = altsolution(A);
	    for(int i=0; i<N; i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
