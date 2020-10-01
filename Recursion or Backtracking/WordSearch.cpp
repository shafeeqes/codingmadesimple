/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent"
cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
/*
DFS : Depth-first search is an algorithm for traversing or searching tree 
or graph data structures. The algorithm starts at the root node and explores
as far as possible along each branch before backtracking
*/
// O(n) time n= no of cells in the grid
// O(n) space

class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
                
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == word[0]){
                    //visited[i][j] = true;
                    if (back(board,word, i ,j ,0))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool back(vector<vector<char>>& board, string word, int i, 
              int j, int k){
        int rows = board.size();
        int cols = board[0].size(); 
        
        if(i<0 or i>= rows or j<0 or j>= cols or k>= word.size() or board[i][j]!=word[k]){
            return false;
        }
        k++;
        if(k== word.size())
            return true;
        
        // dont want this cell to be visited again during this iteration
        char temp = board[i][j];
        board[i][j] = ' ';
        
        bool ans = false;
        for(auto dir:directions){
            int nextI = i+ dir[0];
            int nextJ = j+ dir[1];
            ans = ans or back(board,word,nextI,nextJ,k);
            if(ans)
                return true;
        }
        //we dont want to set the cell as permanently visited
        board[i][j] = temp;
        return ans;
        
    }
    
};


//Alt solution ; just a small change in the visited method
class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
                
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == word[0]){
                    //visited[i][j] = true;
                    if (back(board,word, i ,j ,0,visited))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool back(vector<vector<char>>& board, string word, int i, 
              int j, int k,vector<vector<bool>> &visited){
        int rows = board.size();
        int cols = board[0].size(); 
        
        if(i<0 or i>= rows or j<0 or j>= cols or k>= word.size() or board[i][j]!=word[k]
                        or visited[i][j]){
            return false;
        }
        k++;
        if(k== word.size())
            return true;
        //mark the cells in this iterations as visited
        visited[i][j] = true;
        bool ans = false;
        for(auto dir:directions){
            int nextI = i+ dir[0];
            int nextJ = j+ dir[1];
            ans = ans or back(board,word,nextI,nextJ,k,visited);
            if(ans)
                return true;
        }
        //we dont want to set the cell as permanently visited
        visited[i][j] = false;
        return ans;
        
    }
    
};
