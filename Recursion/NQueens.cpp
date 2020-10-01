/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<int> colPlacements;
        dfs(n,0, colPlacements, ans);
       
        vector<vector<string>> result;
        for(vector<int> A:ans){
            vector<string> v;
            for(int row =0; row<n; row++){
                string s ="";
                for(int i = 0; i < A.size(); i++){
                    if(A[row]==i)
                        s += "Q";
                    else
                        s += ".";
                }
                v.push_back(s);
            }
            result.push_back(v);
        }
        
        return result;
    }
    void dfs(int n, int row, vector<int> colPlacements, vector<vector<int>> &ans){
        
        if(row == n){
            ans.push_back(colPlacements);
        }
        else{
            for(int j = 0; j< n; j++){
                //select this column
                colPlacements.push_back(j);
                if(isValid(colPlacements)){
                    //proceed with this column and return a solution if present
                    dfs(n, row+1, colPlacements, ans);
                }
                //backtracking. undoing our selection
                colPlacements.pop_back();
            }
        }
    }
    
    bool isValid(vector<int> &colPlacements){
        int currRow = colPlacements.size()-1;
        for(int i=0; i<currRow; i++){
            int diff = abs(colPlacements[currRow]-colPlacements[i]);
            //vertically same col or diagonal difference = difference btw both rows
            // so for the Q diagonally in a row just above or below diff = 1
            // or in other words if col difference = row difference, both are in the same               //diagonal
            if(diff ==0 or diff == currRow-i)   
                return false;
        }
        return true;
    }
};
