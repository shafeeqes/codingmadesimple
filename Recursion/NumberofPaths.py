"""
The problem is to count all the possible paths from top left to bottom right of a 
MxN matrix with the constraints that from each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the number of test cases. 
The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:
1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.
"""
#code
## A better solution is given by DP, check that out
def paths(&m,&n):
    if m==1 or n==1:
        return 1
    return paths(m,n-1) + paths(m-1,n)    

def main():
    t = int(input())
    for i in range(t):
        m,n = [int(i) for i in input().strip().split()]
        print(paths(m,n))

if __name__ == '__main__':
    main()
