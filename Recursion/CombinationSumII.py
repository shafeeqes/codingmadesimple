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
"""
same as Combinations, just use i+1 in recursion
and also dont make the initial vector unique
"""
class Solution:
    def make(self,A,temp,index,currSum,target):
        if currSum> target:
            return
        if currSum == target:
            if temp not in self.ans:
                self.ans.append(temp[:])
            return
        
        for i in range(index,len(A)):
            temp.append(A[i])
            self.make(A,temp,i+1,currSum+A[i],target)
            # This is the backtrack step. Append to array, then delete after making calls
            temp.pop()
    
    def combinationSum2(self, A: List[int], target: int) -> List[List[int]]:
        A.sort()
        self.ans = []
        self.make(A,[],0,0,target)
        return self.ans
