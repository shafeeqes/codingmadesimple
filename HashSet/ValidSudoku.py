"""
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
"""
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in range(9):
            check = [0]*9
            for j in range(9):
                curr = board[i][j]
                if curr.isdigit():
                    
                    curr = int(board[i][j])
                    print(check)
                    if check[curr-1]!=0:
                        return False
                    else:
                        check[curr-1]=1
                      
        for j in range(9):
            check = [0]*9
            for i in range(9):
                curr = board[i][j]
                if curr.isdigit():
                    curr = int(board[i][j])
                    if check[curr-1]!=0:
                        return False
                    else:
                        check[curr-1]=1
                       
        box = 0; rows = 0; cols = 0
        print("box start")
        while box != 9:
            check = [0]*9
            for i in range(3*rows,3*(rows+1)):
                for j in range(3*cols,3*(cols+1)):
                    curr = board[i][j]
                    if curr.isdigit():
                        
                        curr = int(board[i][j])
                        if check[curr-1]!=0:
                            return False
                        else:
                            check[curr-1]=1
            box += 1
            cols += 1
            
            if box ==3 or box ==6:
                rows += 1
                cols = 0
      
        return True
            
