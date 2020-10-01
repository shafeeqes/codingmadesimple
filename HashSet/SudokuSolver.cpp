/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

class Solution {
public:
    bool sign;  
    void solveSudoku(vector<vector<char>>& board) {
        sign = false;
        solve(board,0);
        
    }
    
      
    void solve(vector<vector<char>>&board,int n){
        if(n>80){
            sign = true;
            return;
        }
        if(board[n/9][n%9] != '.'){
            solve(board,n+1);
        }
        else{
            for(int i=1; i<=9; i++){
                
                if(check(board,n/9,n%9,i)){
                    board[n/9][n%9]= i +'0';
                    solve(board,n+1);
                    if(sign == true)
                        return;
                    board[n/9][n%9]='.';
                }
            }
        }
        
    }
    
    bool check(vector<vector<char>>& board,int row,int col,int val)
    {
        
        for(int i=0;i<9;i++){
            if(board[row][i]== val+'0' or board[i][col] == val+'0') 
                return false;
        }
        
        int x=3*(row/3);
        int y=3*(col/3);
        
        
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]== val+'0') return false;
            }
        }
        return true;
    }
};
