/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
*/

// Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n= A.size();
        if(n<1)
            return 0;
        int max_current = A[0],max_global =A[0];
        for(int i=1;i<n; i++){
            max_current = max(A[i],max_current+A[i]);
            max_global = max(max_global,max_current);
        }
        return max_global;
    }
};
