/*
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
*/


int Solution::isValidSudoku(const vector<string> &A) {

    if(A.size()<9)
        return 0;
        
    for(int i=0;i<A.size();i++)
    {   
        unordered_set <int> hash;
        string str = A[i];
        for(int j=0;j<str.size();j++)
        {   
            if(isdigit(str[j]))
            {
                int num = str[j]-'0';
                if(hash.find(num)!=hash.end())
                    return 0; 
                hash.insert(num);
            }
        }
    }
    
    for(int j=0;j<9;j++)
    {
        unordered_set<int> hash;
        for(int i=0;i<A.size();i++)
        {
            if(isdigit(A[i][j]))
            {
                int num = A[i][j]-'0';
                if(hash.find(num)!=hash.end())
                    return 0; 
                hash.insert(num);
                
            }
        }
    }
    
    int box = 0, count = 0, row = 0;
    
    while(box != 9)
    {
        unordered_set<int> hash;
        for(int i = 3*row; i < 3*(row+1); i++)
        {
            for(int j = 3*count; j < 3*(count+1); j++)
            {
                if(isdigit(A[i][j]))
                {
                    int num = A[i][j]-'0';
                    if(hash.find(num)!=hash.end())
                        return 0; 
                    hash.insert(num);
                }
            }
        }
        
        count++;
        box++;
        
        if(box == 3 || box == 6)
        {
            row++;
            count = 0;
        }
    }
    return 1;
}
