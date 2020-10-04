/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 
 */
 
 class Solution {
public:
    int search(vector<int>& A, int target) {
        
        int n = A.size();
        int start = 0, end = n - 1;
        int mid;
        while(start <= end){
            mid = start + (end-start)/2;
            if(A[mid] == target){
                return mid;
            }else if (A[mid] < target){
                start = mid + 1;
            }else{
                end = mid -1;
            }
                
        }
        return -1;
        
    }
};
