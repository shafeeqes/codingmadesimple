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
#include<bits/stdc++.h>
using namespace std;
 
vector<int> A(100001);
void SieveOfEratosthenes(int n) { 
    vector<bool> prime(n+1,true);    
    for (int p=2; p*p<=n; p++) {  
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
	A[0]=0;
	A[1]=0;
    for (int p=2; p<=n; p++) {
       	if (prime[p])
    		A[p]=A[p-1]+1;
		else
			A[p]=A[p-1];
	}
}
 
bool isSpecial(int r1, int r2, int A, int i){
	if(A*r2>=i*r1)
		return true;
	return false;
}
 
int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int T;
	cin>>T;
	SieveOfEratosthenes(100000);
	while(T){
		int r1,r2,n;
		string cells;
		cin>>r1>>r2>>n>>cells;
		cells=" "+cells;
		vector<int> dp(n+1,INT_MAX);
		if(cells[1]=='*' || cells[n]=='*'){
			cout<<"No way!"<<endl;
		}
		else{
			dp[0]=0;
			dp[1]=0;;
			for(int i=1;i<=n;i++){
				if(cells[i]!='*' && dp[i]!=INT_MAX){
					if(i+1<=n && cells[i+1]!='*')
						dp[i+1]=min(dp[i+1],dp[i]+1);
					if(i+2<=n && cells[i+2]!='*')
						dp[i+2]=min(dp[i+2],dp[i]+1);
					if(isSpecial(r1,r2,A[i],i) && i+A[i]<=n && cells[i+A[i]]!='*')
						dp[i+A[i]]=min(dp[i+A[i]],dp[i]+1);
				}
			}
			if(dp[n]!=INT_MAX && dp[n]>=0)
				cout<<dp[n]<<endl;
			else	
				cout<<"No way!"<<endl;
		}
		T--;
	}
}
