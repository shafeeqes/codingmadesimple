/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, c
ompute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution(object):
    def trap(self, A):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(A)
        if n == 0:
            return 0
        
        leftmax = [0]*n
        rightmax = [0]*n

        leftmax[0] = A[0]
        for i in range(1,n):
            leftmax[i] = max(A[i],leftmax[i-1])

        rightmax[n-1] = A[n-1]    
        for i in range(n-2,-1,-1):
            rightmax[i] = max(A[i],rightmax[i+1])

        water = 0
        for i in range(0, n): 
            water += min(leftmax[i],rightmax[i]) - A[i] 

        return water
