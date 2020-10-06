"""
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
"""

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        
        n = len(coordinates)
        xdiff = coordinates[1][0]-coordinates[0][0]
        ydiff = coordinates[1][1]-coordinates[0][1]
        
        for i in range(2,n):
            curr_xdiff = coordinates[i][0]-coordinates[i-1][0]
            curr_ydiff = coordinates[i][1]-coordinates[i-1][1]
            
            if curr_xdiff * ydiff != curr_ydiff * xdiff:
                return False
            
        return True
