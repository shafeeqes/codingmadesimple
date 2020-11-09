/*

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1

*/




class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int Sx = 0, Sy = 0, Dx = r -1, Dy = c -1;
    
        int directions[8][2] = {{+1,0},{-1,0},{0,+1},{0,-1},{+1,+1},{+1,-1},{-1,+1},{-1,-1}};
        

        vector<vector<int>> dist(r, vector<int> (c,INT_MAX));
        vector<vector<bool>> processed(r, vector<bool> (c,false));

        priority_queue<pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        if(grid[Sx][Sy] == 1 or grid[Dx][Dy] == 1)
            return -1;
        
        pq.push({1, {Sx,Sy}});
        dist[Sx][Sy] = 1;

        while(!pq.empty()){

            int curr_dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();
            //keep track of processed nodes
            processed[i][j] = true;

            for(int k = 0; k < 8; k++){
                int nextI = i + directions[k][0];
                int nextJ = j + directions[k][1];

                //relax cells in all four dir
                if(nextI >=0 and nextI < r and nextJ >=0 and nextJ < c 
                    and !processed[nextI][nextJ] and grid[nextI][nextJ] != 1){
                   
                    if(curr_dist + 1 < dist[nextI][nextJ]){
                        dist[nextI][nextJ] = curr_dist+1 ;
                        pq.push({dist[nextI][nextJ], {nextI,nextJ}});
                    }
                }
            }
        }
        return dist[Dx][Dy] == INT_MAX ? -1 : dist[Dx][Dy];
    }
};
