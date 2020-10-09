/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

*/



class Solution {
public:
    int m,n;
    vector<int> dir = {0,-1,0,1,0};
    
    int closedIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        int ctr=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j]==0){
                    
                    if(dfs(grid,i,j)) ctr++;
                }
            }   
        }
        return ctr;
    }
    
    bool dfs(vector<vector<int>>& grid, int i,int j){
        
        //if at the boundaries
        if(i<0 || i>=m || j<0 || j>=n) return false;
        
        
        //if surrounded by 1's return true
        if(grid[i][j]==1) return true; 
        
        grid[i][j] = 1;
        
        bool enclosed=true;
        for(int k=0; k<4; k++){
            //equivalent to enclosd = enclosed and dfs(...)
            enclosed &=dfs(grid,i+dir[k],j+dir[k+1]);
        }
        
        return enclosed?true:false;  
    }
};
