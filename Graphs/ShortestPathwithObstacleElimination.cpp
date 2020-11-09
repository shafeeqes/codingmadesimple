/*

Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0

*/



class Solution {
public:
    
    struct cell{
        int x;
        int y;
        int obs;
        
        cell(int x, int y, int obs){
            this-> x = x;
            this-> y = y;
            this-> obs = obs;
        }
    };
    int shortestPath(vector<vector<int>>& A, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int directions[4][2] = {{+1,0},{-1,0},{0,+1},{0,-1}};
        
        int ans = 0;
  
        int r = A.size();
        int c = A[0].size();
   
        int processed[r][c][K+1];
        memset(processed, false, sizeof(processed));
        
        queue<cell> q;
        
        int o;
        o = A[0][0] == 1? 1:0;
        
        if(o==1 and K==0)
            return -1;
        
        q.push(cell(0,0,o));
      
        while(!q.empty()){
            
            int size = q.size();
            
            while(size --){
                cell curr_cell = q.front();
                q.pop();

                int i = curr_cell.x;
                int j = curr_cell.y;
                int obs = curr_cell.obs;

                if(i == r-1 and j == c-1){
                    return ans;
                }
                if(processed[i][j][obs])
                    continue;
                processed[i][j][obs] = true;
                
                for(int k = 0; k < 4; k++){
                    int nextI = i + directions[k][0];
                    int nextJ = j + directions[k][1];

                    if(nextI < 0  or nextI >= r or nextJ < 0 or
                                nextJ >= c)
                        continue;
                       
                    int t = obs;
                    if(A[nextI][nextJ] == 1){
                        t++;
                    }
                    if(t > K)
                        continue;
                       
                    q.push(cell(nextI,nextJ,t));
                        
                }   
            }
            ans ++;
        }
        
        return -1; 
    }
};
