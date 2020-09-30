/*
Given a value N, find the number of ways to make change for N cents,
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

â€‹Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the 
function count() which accepts an array S[] its size m and n as input parameter
and returns the number of ways to make change for N cents.



Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n). 


*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    long long int count( int coins[], int m, int target )
    {
        /*we have to recursively reach target so
        we consider target+1 cols including zero
        and rows are considering 0 elements, then 1, 2
        etc. like [], [1], [1,2], [1,2,3]*/
        vector<vector<long long int> > T( m+1 , vector<long long int> (target+1,0));
        /*first column, ways to make zero
         which will be all 1*/
        for(int i=0; i<m+1; i++){
            T[i][0] = 1;
        }
        /* this is the first row no elements of S 
            are considered. Not required since 
            we set all values to zero*/
        /*for(int j=1; j<target+1; j++){
            T[0][j] = 0;
        }*/
        
        
        for(int i=1; i<m+1; i++){
            for(int j=1;j<target+1;j++){
                /* if the current coin is greater than the 
                total coin value , skip
                */
                if(coins[i-1]>j)
                    T[i][j] = T[i-1][j];
                else
                    //Total ways is equal to if we skip the current coin
                    //ie, T[i-1][j] + if we use the coin, then the value will
                    // be sum of the previos row plus the total amount - this 
                    // coin value. which is taken from same row
                    T[i][j] = T[i-1][j] + T[i][j-coins[i-1]]; 
            }
        }
        return T[m][target];
    }
        
};




// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
