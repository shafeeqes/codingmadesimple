/*

Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

Examples:

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1
Output: 4
*/

class Solution{

	public:
	int countSubset(int arr[], int sum) 
        {// Calculate sum of all elements 
		
		// Create an array to store results of subproblems 
		int dp[n+1][sum+1] = {0}; 

		// Initialize first column as true. 0 sum is possible  
		// with all elements. 
		for (int i = 0; i <= n; i++) 
		    dp[i][0] = 1; 

		// Initialize top row, except dp[0][0], as false. With 
		// 0 elements, no other sum except 0 is possible 
		for (int i = 1; i <= sum; i++) 
		    dp[0][i] = 0; 

		// Fill the partition table in bottom up manner 
		for (int i = 1; i <= n; i++) 
		{ 
		    for (int j = 1; j <= sum; j++) 
		    { 
			// If i'th element is excluded 
			dp[i][j] = dp[i-1][j]; 

			// If i'th element is included 
			if (arr[i-1] <= j) 
			    dp[i][j] += dp[i-1][j-arr[i-1]]; 
		    } 
		} 
    
        	return dp[sum]; 
	}
	
};
