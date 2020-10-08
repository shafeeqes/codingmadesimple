/*
Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.
 */
 
 /*
 
 We already know chunks of O which remain as O are the ones which have at least one O connected to them which is on the boundary.

Use BFS starting from ‘O’s on the boundary and mark them as ‘B’, then iterate over the whole board and mark ‘O’ as ‘X’ and ‘B’ as ‘O’.
 */
 
void floodfill(vector<vector<char> >&A ,int x,int y, char prev, char final){
    
    int rows = A.size(), cols = A[0].size();
    
    if(x < 0 || x >= rows || y<0 || y>=cols)
        return;
    if(A[x][y]!= prev)
        return;
        
    A[x][y] = final;
    
    floodfill(A,x+1,y,prev,final);
    floodfill(A,x-1,y,prev,final);
    floodfill(A,x,y+1,prev,final);
    floodfill(A,x,y-1,prev,final);
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows = A.size(), cols = A[0].size();
    
    for(int i=0 ;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (A[i][j] == 'O')
                A[i][j] = '-';
        }
    }
    int k;
    
    for(k = 0; k<cols; k++){
        if(A[0][k]== '-')
            floodfill(A,0,k,'-','O');
        if(A[rows-1][k]== '-')
            floodfill(A,rows-1,k,'-','O');    
    }

    for(k = 0; k<rows; k++){
        if(A[k][0]== '-')
            floodfill(A,k,0,'-','O');
        if(A[k][cols-1]== '-')
            floodfill(A,k,cols-1,'-','O');
    }
  
  
    for(int i=0 ;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (A[i][j] == '-')
                A[i][j] = 'X';
        }
    }        
}

