/*Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:

1 <= A, B <= 500
Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.
    */
    
 //Minimum steps, so BFS
 // O(n^2) in the worst case
    
int Solution::knight(int r, int c, int start_i, int start_j, int end_i, int end_j) 
{
    if(start_i == end_j and start_j == end_j)
        return 0;
        
    vector<vector<int>> board(r+1, vector<int> (c+1,0));
    vector<vector<int>> directions = {{+1,+2},{+1,-2},{+2,+1},{+2,-1},{-1,+2},
                                            {-1,-2},{-2,+1},{-2,-1}};
    
    queue<pair<int,int>> Q;
    Q.push({start_i,start_j});
    int d = 0;
    //mark the start node visited
    board[start_i][start_j] = 1;
    //bfs
    while(!Q.empty()){
        
        int size = Q.size();
        while(size--)
        {
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();
            
            if(i == end_i and j == end_j)
                return d;
          
            for(auto direction:directions)
            {
                int nextI = i + direction[0];
                int nextJ = j + direction[1];
                //if there is a valid direction, push it to the queue
                //mark it visited
                if(nextI >= 1 and nextJ >=1 and nextI < board.size() 
                        and nextJ<board[nextI].size() and board[nextI][nextJ] == 0)
                {
                    Q.push({nextI,nextJ});
                    //do this here itself not while popping the node
                    //because unnecessary nodes will be added to the queue
                    //because of that
                    board[nextI][nextJ] = 1;  
                }        
            }
        }
        d++;
    }
   
    return -1;
}

