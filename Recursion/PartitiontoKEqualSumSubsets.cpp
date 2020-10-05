/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/


class Solution {
public:
    
    int target;
    vector<bool> visited;    
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int total = 0;
        int maxval = INT_MIN;
        
        for(int i:A){
            total += i;
            if(i > maxval)
                maxval = i;
        }
        
        int n =A.size();
		visited.resize(n, 0);
        
        if(k == 0 or total %k != 0 or maxval > total/k)
            return false;
        
        target = total/k;
        return solve(A,k,0,0);
    }
    
    bool solve(vector<int> &A, int k, int sum, int index){
        
        //only one subset true. its sum should br equal to target. if(k==0) will also do fine
        if(k == 1){
            return true;
        } 
        //if the current sum is target, solve for remaining subsets
        if(sum == target){
            return solve(A, k-1, 0, 0);
        }
        for(int i = index; i < A.size(); i++){
            if(!visited[i] and A[i]+sum <= target){
                visited[i] = true;
                if(solve(A, k, sum + A[i], i + 1)){
                    return true; 
                }
                visited[i] = false;
            }
        }
        return false;
    }
};
