
Just we have to check if the binary form of that Number has only patterns of 10 and 01.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 5;
	int a = 1;
	int b = 2;

	bool ans = true;

	while(n > 0 and n >= b){
		int t = n & 3;
		if(t != a and t != b){
			ans = false;
			break;
		}
		n = n >> 1;
	}

	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
