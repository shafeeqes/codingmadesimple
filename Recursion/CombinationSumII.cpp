/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/
//Space complexity : O(n)
//Time complexity 2^n, we are either taking or not taking for all elements

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
         vector<vector<int> > ans;
        if(A.size()==0)
            return ans;
        vector<int> temp;        
        sort(A.begin(),A.end());

        make(0,0,temp,A,target,ans);
        return ans;
    }
    void make(int index,int CurrSum,vector<int> temp,vector<int> &A,int B,vector<vector<int> > &ans)
    {
        if(CurrSum>B)
            return;
        if(CurrSum==B){
            ans.push_back(temp);
            return;
        }
        if (index == A.size())
            return;

        for(int i=index;i<A.size();i++){
            //To avoid duplicates
            //But you still cant pass unique vector instead of A like Combination Sum 1
            //because we can have elements repeated. only not the same pattern(vector)
            if(i==index || A[i]!=A[i-1]){
                temp.push_back(A[i]);
              //This is the backtrack step. Append to array, then delete after making calls
                make(i+1,CurrSum+A[i],temp,A,B,ans);
                temp.pop_back();
            }
        }
        
    }
};
