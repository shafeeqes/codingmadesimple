/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& A) {
    
        vector<vector<int>> ans;
        make(0, A, ans);
        
        return ans;
    }
    void make(int index,  vector<int> &A, vector<vector<int>> &ans){
        
        if(index >= A.size()){
            ans.push_back(A);
            return;
        }
        
        for(int i = index; i < A.size(); i++){
            swap(A[i],A[index]);
            make(index +1, A, ans);
            swap(A[i],A[index]);
        }
    }
};
