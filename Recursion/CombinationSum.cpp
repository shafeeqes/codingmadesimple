"""
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
"""
/*
same as combination sum 2, but he we can have same element multiple times
but we still eliminate duplicates in the array
*/
/*
//Space complexity : O(n)
//Time complexity 2^n, we are either taking or not taking for all elements
*/


void make(int index,int CurrSum,vector<int> temp,vector<int> &A,int target,vector<vector<int> > &ans)
{
    if(CurrSum>target)
        return;
    if(CurrSum==target){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<A.size();i++){
        temp.push_back(A[i]);
        make(i,CurrSum+A[i],temp,A,target,ans);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int> > ans;
    if(A.size()==0)
        return ans;
    
    vector<int> temp;        
    sort(A.begin(),A.end());
    vector<int> unique;
    for (int i = 0; i < A.size(); i++) 
        if (i == 0 || A[i] != A[i-1]) 
            unique.push_back(A[i]);
        
    make(0,0,temp,unique,B,ans);
   
    return ans;
}
