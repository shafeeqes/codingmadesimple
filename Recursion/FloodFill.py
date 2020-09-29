"""
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0

Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your 
task is to replace color of the given pixel and all adjacent
(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. 
  Then T test cases follow. The first line of each test case contains Two integers
  N and M denoting the size of the matrix. Then in the next line are N*M space 
  separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.
"""
 ## Solution 
  
def floodfill(A,n,m,i,j,c,k):
    # if the indices are out of bounds or the element
    #not equal to our key
    if i<0 or i>=n or j<0 or j>=m or A[i][j]!=c :
        return
    A[i][j] = k
    ##recursive call to adjacent cells
    floodfill(A,n,m,i+1,j,c,k)
    floodfill(A,n,m,i-1,j,c,k)
    floodfill(A,n,m,i,j+1,c,k)
    floodfill(A,n,m,i,j-1,c,k)

def array_to_matrix(arr,n,m):
    matrix = []
    arr_index = 0
    for j in range(0,n):
          row = []
          for k in range(0,m):
                row.append(arr[arr_index])
                arr_index = arr_index + 1
          matrix.append(row)
    return matrix

def printMatrix(matrix):
    for row in matrix:
        for item in row:
            print(item, end=" ")
    print()
      
def main():
    t = int(input())
    for i in range(t):
        n,m = [int(i) for i in input().strip().split()]
        A = [int(x) for x in input().strip().split()]
        x,y,k = [int(i) for i in input().strip().split()]
        A = array_to_matrix(A,n,m);
        floodfill(A,n,m,x,y,A[x][y],k)
        printMatrix(A)


if __name__ == '__main__':
    main()
