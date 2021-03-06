/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

*/
/*
The recursive solution is very slow, because its runtime is exponential

The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example:
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even
*/

//O(n*s) space
// O(n*s) time

//NB: while counting ways unlike the other similar problems, j should start from 0. not 1

class Solution {
public:
        
        //we can consider the whole array into two sets, one with positive values 
        //and one with negative
        //then S1 + S2 = SUM
        //S1- S2 = target
        //S1 - (SUM-S1) = target
        // 2S1 - SUM = target
        // S1 = (SUM + target)/2
        
       
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int sum) {
       
        int n = nums.size();
        int dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <=n ; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i-1][j];
                
                if(nums[i-1] <= j){
                    dp[i][j] += dp[i-1][j - nums[i-1]];
                }
            }
        }
      
        return dp[n][sum];
     
    }
    
};

//O(s) space
// O(n*s) time

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};
