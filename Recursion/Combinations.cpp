/*"""
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
You may return the answer in any order.
 
Example 1:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:
Input: n = 1, k = 1
Output: [[1]]
"""*/
// almost similar to combination sum, just check the size
// of temp here

void make(vector<int> &A, vector<int> temp,int k,int index,vector<vector<int> > &ans)
{
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    
    for(int i=index;i<A.size();i++){
        temp.push_back(A[i]);
        make(A,temp,k,i+1,ans);
        temp.pop_back();
    }
}
 
vector<vector<int> > Solution::combine(int n, int k) {
    
    vector<vector<int> > ans;
    vector<int> A;
    for(int i=1;i<=n;i++){
        A.push_back(i);
    }
    vector<int> temp;
    make(A,temp,k,0,ans);
    return ans;    
}
