/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() 
which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 106
*/

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
        {// Calculate sum of all elements 
        int sum = 0;  
        for (int i = 0; i < n; i++) 
            sum += arr[i]; 
      
        // Create an array to store results of subproblems 
        bool dp[n+1][sum+1]; 
      
        // Initialize first column as true. 0 sum is possible  
        // with all elements. 
        for (int i = 0; i <= n; i++) 
            dp[i][0] = true; 
      
        // Initialize top row, except dp[0][0], as false. With 
        // 0 elements, no other sum except 0 is possible 
        for (int i = 1; i <= sum; i++) 
            dp[0][i] = false; 
      
        // Fill the partition table in bottom up manner 
        for (int i=1; i<=n; i++) 
        { 
            for (int j=1; j<=sum; j++) 
            { 
                // If i'th element is excluded 
                dp[i][j] = dp[i-1][j]; 
      
                // If i'th element is included 
                if (arr[i-1] <= j) 
                    dp[i][j] += dp[i-1][j-arr[i-1]]; 
            } 
        } 
       
        // Initialize difference of two sums.  
        int diff = INT_MAX; 
          
        // Find the largest j such that dp[n][j] 
        // is true where j loops from sum/2 t0 0 
        for (int j=sum/2; j>=0; j--) 
        { 
            // Find the  
            if (dp[n][j] == true) 
            { 
                diff = sum-2*j; 
                break; 
            } 
        } 
        return diff; 
	}
	
};
