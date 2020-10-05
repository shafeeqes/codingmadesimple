/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}


Input: N = 3, arr[] = {10, 5, 4, 3 , 2}
Output: 10
All the items are in decreasing order


Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
*/
//Just a variation of the longest increasing subsequence

class Solution{
	public:
	int maxSumIS(int A[], int n)  
	{  
	    vector<int> dp(n);
	    if(n<1) return 0;
	    int ans = A[0];
	    dp[0] = A[0];
	    for(int j = 1; j < n; j++){
	        dp[j] = A[j];
	        for(int i = 0; i< j; i++){
	            if(A[j]>A[i]){
	                dp[j] = max(dp[j], A[j] + dp[i]);
	            } 
	        }
	        ans = max(dp[j],ans);
	    }
	    return ans;
	}  
};
