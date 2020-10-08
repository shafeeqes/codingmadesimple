/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j]!='1')
            return;
        grid[i][j]='x';
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0)
            return 0;
        int count =0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                   count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
