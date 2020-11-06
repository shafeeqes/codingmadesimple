/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/


class Solution {
public:
    bool canPartition(vector<int>& A) {
     
        int total = 0;
        for(int i:A){
            total += i;
        }
        if(total %2 != 0)
            return false;
        
        int n = A.size();
        int subsetSum = total/2;
        vector<vector<optional<bool>>> dp(n + 1, vector<optional<bool>> (subsetSum +1, nullopt));
   
        return dfs1(A, 0, subsetSum, dp);
        
    }
    bool dfs(vector<int> &A, int index, int sum, vector<vector<optional<bool>>> &dp){
        
        if(sum == 0)
            return true;
        
        if(sum < 0 or index >= A.size())
            return false;
        
        if(dp[index][sum] != nullopt){
            return (dp[index][sum] == true);
        }
    
        //either include this number or not include this number
        bool result = dfs(A, index + 1, sum, dp) or dfs(A, index+1, sum - A[index], dp);
        
        dp[index][sum] = result;
        
        return result;
    }
};
