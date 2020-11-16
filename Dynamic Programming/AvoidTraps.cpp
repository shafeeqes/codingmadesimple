// /https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/avoid-traps-0b92455e/

/*


// Sample code to perform I/O:
 
#include <iostream>
 
using namespace std;
 
int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> SieveofEratosthenes(int N){
	vector<bool> prime(N+1, true);
	vector<int> v(N,0);
	prime[0] = false;
	prime[1] = false;

	for(int i = 2; i*i <= N; i++){
		if(prime[i]){
			for(int k = i*i; k <= N; k += i){
				prime[k] = false;
			}
		}
	}

	v[0] = 0;
	v[1] = 0;

	for(int i = 2; i <= N; i++){
		v[i] = v[i-1];
		if(prime[i])
			v[i] += 1;
	}

	return v;
}


bool isSpecial(int r1, int r2, int A, int i){
	if(A * r2 >= i*r1)
		return true;
	return false;
}

int solve(string s, int r1, int r2, vector<int> &v, int n){
	
	vector<int> dp(n+1,INT_MAX);
	dp[0] = 0;
	dp[1] = 0;
	
	for(int i = 1; i < n + 1; i++){
		//if dp[i] == INT_MAX it cannot be reached. 
		if(s[i] == '#' && dp[i]!=INT_MAX){
			if(i+1 < n+1 and s[i+1] == '#'){
				dp[i+1] = min(dp[i+1], dp[i] + 1);
			}
			if(i+2 < n+1 and s[i+2] == '#'){
				dp[i+2] = min(dp[i+2], dp[i] + 1);
			}
			if(i + v[i] < n+1 and isSpecial(r1, r2, v[i], i) and s[i+v[i]] == '#'){
				dp[i + v[i]] = min(dp[i + v[i]], dp[i] + 1);
			}
		}
	}

	/*for(int i:dp){
		cout<<i<<" ";
	}*/

	if(dp[n] == INT_MAX)
		return -1;
	else
		return dp[n];
}

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int t;
	cin>>t;
	
	vector<int> A = SieveofEratosthenes(100001);

	while(t--){
		int r1, r2;
		cin>>r1>>r2;

		int n;
		cin>>n;
		string s;
		cin>> s;

		int ans;
		s = " " + s;
		if(s[1] == '*' or s[n] == '*'){
			ans = -1;
			cout<<"No way!"<<endl;
		}
		else{
			ans = solve(s,r1,r2,A,n);

			if(ans > 0)
				cout<<ans<<endl;
			else
				cout<<"No way!"<<endl;
		}
	}
} 
