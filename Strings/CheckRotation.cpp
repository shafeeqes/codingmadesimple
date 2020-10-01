/*Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

*/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s1,s2;
	    cin>>s1>>s2;
	    int ans = 0;
	    int k = 2;
	    int n = s1.size();
	    
	    string check1 = s1.substr(k,n-k);
	    for(int i=0;i<k;i++)
	        check1 += s1[i];
	    
	    string check2;
	    for(int i=n-k;i<n;i++)
	        check2 += s1[i];
	    check2 += s1.substr(0,n-k);
	 
	    if(check1 == s2 or check2 == s2)
	        ans = 1;
	    cout<<ans<<endl;     
	}
	return 0;
}
