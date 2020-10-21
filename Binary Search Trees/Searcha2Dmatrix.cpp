/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size();
        if(r < 1)
            return false;
        int c = matrix[0].size();
        if(c < 1)
            return false;
        
        int mid1, mid2;
        
        int first = 0, last = r - 1;
        while(first <= last){
            
            mid1 = first + (last - first)/2;
            
            if(matrix[mid1][0] <= target and matrix[mid1][c-1] >= target){
                int start = 0, end = c-1;
                
                while(start <= end){
                    mid2 = start + (end-start)/2;
                    
                    if(matrix[mid1][mid2] == target){
                        return true;
                    }
                    else if (matrix[mid1][mid2] < target){
                        start = mid2 + 1;
                    }
                    else{
                        end = mid2 - 1;
                    }
                } 
            }
            if(matrix[mid1][0] > target){
                last = mid1 - 1;
            }
            else{
                first = mid1 + 1;
            }
        }
        
        return false;
    }
};


// same solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int B) {
        
        int m = A.size();
        if(m<1) return false;
        int n=A[0].size();
        if(n<1) return false;
        int t =0, b=m-1,mid1,mid2,l,r;

        while(t<=b)
        {
            l = 0; r =n-1;
            mid1 = (t+b)/2;

            if(A[mid1][0]==B)
                return 1;

            else if(A[mid1][0]<B)
            {
                t = mid1+1;
                while(l<=r && (A[mid1][n-1]>=B))
                {
                    mid2 = (l+r)/2;
                    if(A[mid1][mid2]==B)
                        return true;
                    else if(A[mid1][mid2]<B)
                        l=mid2+1;
                    else 
                        r= mid2-1;
                }
            }
            else
                b = mid1-1;
        }
        return false;
    }
};
