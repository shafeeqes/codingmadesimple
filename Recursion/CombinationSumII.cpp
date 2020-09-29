"""
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
"""
void make(int index,int CurrSum,vector<int> temp,vector<int> &A,int B,vector<vector<int> > &ans, map<vector<int>,bool> &m)
{
    if(CurrSum>B)
        return;
    if(!m[temp] && CurrSum==B)
    {
        ans.push_back(temp);
        m[temp]=true;
        return;
    }
    if (index == A.size())
        return;
        
    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        make(i+1,CurrSum+A[i],temp,A,B,ans,m);
        temp.pop_back();
    }
        
}
 
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int> > ans;
    if(A.size()==0)
        return ans;
    map<vector<int>,bool> m;
    vector<int> temp;        
    sort(A.begin(),A.end());
    
    make(0,0,temp,A,B,ans,m);
    return ans;
}
