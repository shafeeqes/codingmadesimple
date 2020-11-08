//Asked in Google

/*

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times
 */
 
 
 
int Solution::solve(int r, int c, vector<string> &C) {
    
    int Sx = 0, Sy = 0, Dx = r -1, Dy = c -1;
    
    int directions[4][4] = {{+1,0}, {-1,0}, {0,+1}, {0,-1}};
    char charmap[4] = {'D','U','R','L'};
    
    vector<vector<int>> dist(r, vector<int> (c,INT_MAX));
    vector<vector<bool>> processed(r, vector<bool> (c,false));
    
    priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
    pq.push({0, {Sx,Sy}});
    dist[Sx][Sy] = 0;
    
    while(!pq.empty()){
        
        int curr_dist = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        
        pq.pop();
        //keep track of processed nodes
        processed[i][j] = true;
                
        for(int k = 0; k < 4; k++){
            int nextI = i + directions[k][0];
            int nextJ = j + directions[k][1];
            
            //relax cells in all four dir
            if(nextI >=0 and nextI < r and nextJ >=0 and 
                        nextJ < c and !processed[nextI][nextJ]){
                int t;
                if(C[i][j] == charmap[k]){
                    t = curr_dist;
                }else{
                    t = curr_dist + 1;
                }
                if(t < dist[nextI][nextJ]){
                    dist[nextI][nextJ] = t ;
                    pq.push({dist[nextI][nextJ], {nextI,nextJ}});
                }
            }
        }
    }
    
    return dist[Dx][Dy];
}

