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
    unordered_map<int,unordered_map<int,bool>> dp;
    bool canPartition(vector<int>& A) {
     
        int total = 0;
        for(int i:A){
            total += i;
        }
        
        if(total %2 != 0)
            return false;
        
        return solve(A,0,total/2);
        
    }
    bool solve(vector<int> &A, int index, int sum){
        
        if(dp[index].find(sum)!= dp[index].end()){
            return dp[index][sum];
        }
        if(sum == 0)
            return true;
        
        if(sum < 0 or index == A.size())
            return false;
        
        for(int i = index; i < A.size(); i++){
            dp[i][sum] = solve(A, i+1, sum-A[i]);
            
            if(dp[i][sum])
               return 1;
        }
        return dp[index][sum] = 0;
    }
};
