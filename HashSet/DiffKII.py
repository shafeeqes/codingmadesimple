/*Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.
*/


class Solution:
	# @param A : tuple of integers
	# @param target : integer
	# @return an integer
	
	def diffPossible(self, A, target):
	        
	    hashset = set()
	    for i in range(len(A)):
	        req1 = target + A[i]
	        req2 = A[i] - target
	        
	        if req1 in hashset or req2 in hashset:
	            return 1
	        hashset.add(A[i])
	        
	    return 0
