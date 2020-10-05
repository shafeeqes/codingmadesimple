/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

//O(log n)


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        
        //Storing the result in res array.
        vector<int> res {-1,-1};
        
        //Checking for first occurance(I.e always search towards left of array).
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                res[0]=mid;
                high=mid-1;
            }
            else if(target>nums[mid])
            low=mid+1;
            else if(target<nums[mid])
            high=mid-1;
            
        }
        
        low=0; high=nums.size()-1;
        //Checking for last occurance(I.e always search towards right of array)
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                res[1]=mid;
                low=mid+1;
            }
            else if(target>nums[mid])
            low=mid+1;
            else if(target<nums[mid])
            high=mid-1;
            
        }
        return res;
        
    }
};




class Solution {
public:
    
    int x;
    int min_index = INT_MAX, max_index = INT_MIN;
    
    vector<int> searchRange(vector<int>& A, int target) {
        x = target;
        int n= A.size();
        
        vector<int> ans = {-1,-1};
        
        if(n == 0){
            return ans;
        }
        
        int l= 0, r = n-1;
        findMinIndex(A, l, r);
        findMaxIndex(A, l, r);
        
        if(min_index == INT_MAX || max_index == INT_MIN){
            return ans;
        }
        else{
            ans[0] = min_index;
            ans[1] = max_index;
            return ans;
        }
    }
    
    void findMinIndex(vector<int> &A, int l, int r){
        int mid = (l+r)/2;
        //instead of returning when x is found we go further left
        if(l >= r){
            if(A[l] == x){
                min_index = min(min_index, l);
            } 
            return;
        }
        
        if(A[mid] == x){
            min_index = min(min_index, mid);
        } 
        
        //if matches go left 
        if(A[mid] < x){ 
            findMinIndex(A, mid+1, r);
        }
        else{ 
            findMinIndex(A, l, mid-1);
        }
    }
    void findMaxIndex(vector<int> &A, int l, int r){
        int mid = (l+r)/2;
        
        if(l >= r){
            if(A[l] == x){
                max_index = max(max_index, l);
            } 
            return;
        }
        
        if(A[mid] == x){
            max_index = max(max_index, mid);
        } 
        
        //if matches go right
        if(A[mid] <= x){
            findMaxIndex(A,mid+1, r);
        }
        else{
            findMaxIndex(A,l, mid-1);
        }
    }
};


