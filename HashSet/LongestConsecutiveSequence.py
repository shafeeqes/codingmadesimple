/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution:
    def longestConsecutive(self, A: List[int]) -> int:
        
        hashset = set(A)
      
        ans = 0
        for x in hashset:
            if x - 1 not in hashset:
                i = x
                count = 0
                while i in hashset:
                    i +=1
                    count += 1
                ans = max(ans,count)

        return ans
