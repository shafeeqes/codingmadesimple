/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent"
cells are those horizontally or vertically neighboring. The same letter cell may not be used 
more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> ans = new ArrayList<String>();
        
        for(String word:words){
            boolean doesExist = false;
            for(int i = 0; i < board.length; i++ ){
                if(doesExist)
                    break;
                for (int j = 0; j < board[i].length; j++){
                    if (word.charAt(0) == board[i][j]){
                        if(dfs(board,word,i,j,0)){
                            ans.add(word);
                            doesExist = true;
                            break;
                        }
                    }    
                }
            }
        }
        return ans;
    }
    public boolean dfs(char[][] board, String word, int i, int j, int k){
        
        if(k == word.length())
            return true;
                
        if(i < 0 || i >= board.length || j < 0 || j >= board[i].length || 
            board[i][j] != word.charAt(k)){
            return false;
        }
              
        char temp = board[i][j];
        board[i][j] = ' ';
        
        boolean found = dfs(board, word, i + 1, j, k + 1 ) ||
                        dfs(board, word, i - 1, j, k + 1) ||
                        dfs(board, word, i, j + 1, k + 1) ||
                        dfs(board, word, i, j - 1, k + 1);
        
        board[i][j] = temp;
        return found;
    }
}
