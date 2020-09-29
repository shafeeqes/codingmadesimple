/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/*
Space complexity : O(n)
Time Complexity: 2^n
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        int index=0;
        vector<int> temp;
        make(A,ans,temp,index);
        return ans;
    }
    void make(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index){
        ans.push_back(temp);

        for(int i=index;i<A.size();i++){
            temp.push_back(A[i]);
            make(A,ans,temp,i+1);
            temp.pop_back();
        }
    }
 
};
