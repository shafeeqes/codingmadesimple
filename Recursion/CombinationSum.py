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


class Solution:
    def make(self,A,temp,index,currsum,reqsum):
        if currsum>reqsum:
	        return
        if currsum == reqsum:
	        self.ans.append(temp[:])
		return
            
        for i in range(index,len(A)):
	        temp.append(A[i])
	        self.make(A,temp,i,currsum+A[i],reqsum)
	        temp.pop()
	
    def combinationSum(self, A: List[int], target: int) -> List[List[int]]:
        A = list(set(A))
        A.sort()
        self.ans = []
        self.make(A,[],0,0,target)
        self.ans.sort()
        return self.ans    
