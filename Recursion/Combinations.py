"""
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
"""
## almost similar to combination sum, just check the size
# of temp here
class Solution:
    # @param A : integer
    # @param B : integer
    # @return a list of list of integers
    def make(self, A, temp, index, k):
        
        if len(temp) == k:
            self.ans.append(temp[:])
            return
        for i in range(index,len(A)):
            temp.append(A[i])
            self.make(A,temp,i+1,k)
            temp.pop();
    
    def combine(self, n,k):
        A = [i for i in range(1,n+1)]
        self.ans = []
        self.make(A,[],0,k)
        return self.ans
