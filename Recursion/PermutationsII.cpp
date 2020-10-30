/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Backtracking is a nightmare for this problem.

The solution of "backtracking" is not efficient in spece since its creating arrays memories for each 
depth of the recursion function. If you do not pass by value, the swap action will disturb the sorted 
sequence and you are going to meet repeating answers.
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& A) {
        
        sort(A.begin(),A.end());
        
        vector<vector<int>> ans;
        make(0, A, ans);
        
        return ans;
    }
    void make(int index,  vector<int> A, vector<vector<int>> &ans){
        
        if(index >= A.size()){
            ans.push_back(A);
            return;
        }
        
        for(int i = index; i < A.size(); i++){
            if(i!=index and A[i] == A[index])
                continue;
            swap(A[i],A[index]);
            make(index +1, A, ans);
        }
    }
};
