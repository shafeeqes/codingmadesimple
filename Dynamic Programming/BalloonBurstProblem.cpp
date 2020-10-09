/*Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Accepted

*/
class Solution {
public:
   int maxCoins(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> v(nums.size()+2,1);
        for(int i=0;i<nums.size();i++)
        {
            v[i+1]=nums[i];
        }
        vector<vector<int>> dp(v.size(),vector<int> (v.size(),-1));
        return helper(v,1,v.size()-1,dp);
    }
    
    int helper(vector<int> &v, int i, int j,vector<vector<int>> &dp)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]>=0)
            return dp[i][j];
        int cost=INT_MIN;
        for(int k = i;k <= j-1; k++)
        {
            cost = max(cost, helper(v,i,k,dp) + helper(v,k+1,j,dp) + v[i-1]*v[k]*v[j]);
        }
        dp[i][j] = cost;
        return cost;
    }
};
