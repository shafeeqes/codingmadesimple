/*
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. 
Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all 
permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void permute(string a, int l, int r,vector<string> &ans)  
{  
    // Base case  
    if (l == r)  
        ans.push_back(a);  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
            // Swapping done  
            swap(a[l], a[i]);  
            // Recursion called  
            permute(a, l+1, r,ans);  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  
  
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int n = str.size();
	    vector<string> ans;
	    permute(str,0,n-1,ans);
	    sort(ans.begin(),ans.end());
	    for(int i =0 ; i<ans.size(); i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}