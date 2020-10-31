/*
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is
from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line 
of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void merge(vector<int> &A, int l, int r, long long int &count){
    
    int m = l +(r- l)/2;
    int i = l;
    int j = m + 1;
    
    vector<int> ans;
    
    while(i <= m and j <= r){
        if(A[i] > A[j]){
            count += m - i +1;
            ans.push_back(A[j]);
            j++;
        }else{
            ans.push_back(A[i]);
            i++;
        }
    }
    while(i <= m){
        ans.push_back(A[i]);
        i++;
    }
    while(j <= r){
        ans.push_back(A[j]);
        j++;
    }
    
    for(int k = l; k <=r; k++){
        A[k] = ans[k-l];
    }
}
void mergesort(vector<int> &A, int l, int r, long long int &count){
    
    if(l >= r)
        return;
    int m = l + (r - l)/2;
    
    mergesort(A, l, m, count);
    mergesort(A, m+1, r, count);
    
    merge(A, l, r, count);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    vector<int> A;
	    for(int i=0;i<N;i++){
	        int temp;
	        cin>>temp;
	        A.push_back(temp);
	    }
	    long long int count = 0;
	    mergesort(A,0,N-1,count);
	    cout<<count<<endl;
	}
	return 0;
}



using namespace std;
#include<bits/stdc++.h>

vector<int> merge(vector<int>&left, vector<int>&right,long long int &count){
    vector<int> ans;
    int nL = left.size(), nR = right.size();
    int i = 0, j =0;
   
    while(i<nL and j<nR){
        if(left[i]<= right[j]){
            ans.push_back(left[i]);
            i++;
        }
        else{
            count += (nL-i);
            ans.push_back(right[j]);
            j++;
        }
    }
    while(i<nL){
        ans.push_back(left[i]);
        i++;
    }
    while(j<nR){
        ans.push_back(right[j]);
        j++;
    }
    return ans;
}
vector<int> mergesort(vector<int> &A,long long int &count){
    int n = A.size();
    if(n<1)
        return {};
    if(n == 1)
        return {A[0]};
    int mid = (n-1)/2;
    vector<int> left, right;
    for(int i=0; i<=mid; i++)
        left.push_back(A[i]);
    for(int i=mid+1; i<n; i++)
        right.push_back(A[i]);
    
    vector<int> leftv= mergesort(left,count);
    vector<int> rightv= mergesort(right,count);
    return merge(leftv,rightv,count);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    vector<int> A;
	    for(int i=0;i<N;i++){
	        int temp;
	        cin>>temp;
	        A.push_back(temp);
	    }
	    long long int count = 0;
	    vector<int> ans= mergesort(A,count);
	    cout<<count<<endl;
	}
	return 0;
}
