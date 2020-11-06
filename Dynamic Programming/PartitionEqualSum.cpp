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

/*Approach 3: Bottom Up Dynamic Programming
Intuition

This is another approach to solving the Dynamic Programming problems. We use the iterative approach and store 
the result of subproblems in bottom-up fashion also known as Tabulation.

Algorithm

We maintain a 2D array , \text{dp}[n][\text{subSetSum}]dp[n][subSetSum] For an array element ii and sum jj in array \text{nums}nums,

\text{dp}[i][j] = \text{true}dp[i][j]=true if the sum jj can be formed by array elements in subset \text{nums[0]} ..
\text{nums[i]}nums[0]..nums[i],otherwise \text{dp}[i][j] = \text{false}dp[i][j]=false

\text{dp}[i][j]dp[i][j] is \text{true}true it satisfies one of the following conditions :

Case 1) sum jj can be formed without including i^{th}i 
th
  element,
\text{if } \text{dp}[i-1][j] == \text{true}if dp[i−1][j]==true

Case 2) sum jj can be formed including i^{th}i 
th
  element,
\text{if } \text{dp}[i-1][j - \text{nums}[i]] == \text{true}if dp[i−1][j−nums[i]]==true
*/

//O(n*subsetSum)

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
        
        //similar to coin change problem
        //rows indicate 0 elements, 0-1 elements, 0-2 elements etc..
        //cols indicate subset sum
        vector<vector<int>> dp(n + 1, vector<int>(subsetSum +1, false));
        //with 0 elements only zero sum is possible, all others are zero
        
        //for zero sum column, all rows are 1
        for(int i = 0; i < n +1; i++){
            dp[i][0] = 1;
        }
    
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < subsetSum + 1; j++){
                if(A[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] or dp[i-1][j - A[i-1]];
            }
        }
        
        return dp[n][subsetSum];
    }
    
};

//Top down dp
//O(2^n)

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
