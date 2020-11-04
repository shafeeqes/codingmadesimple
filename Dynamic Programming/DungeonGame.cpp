/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point
drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these 
rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward 
in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows 
the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	  3
-5	    -10	  1
10	    30	  -5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        
        int r = A.size();
        int c = A[0].size();
        
        int dp[r][c];
        memset(dp, 0, sizeof(dp));
        
         //we do bottom up dp
         //if the destination is negative, we keep that value, or if its positive, we set it as zero
         // zero implies we do not need any health in the current cell to succesfully reach the goal
        dp[r-1][c-1] = A[r-1][c-1] <= 0 ? A[r-1][c-1]: 0;
        
        // for the right most col and bottom most row there is only one way to reach the next cell,
        //so we update accordingly
        for(int i = r-2; i >= 0; i--){
            dp[i][c-1] = min(0, dp[i+1][c-1] + A[i][c-1]);
        }
        
        for(int j = c-2; j >= 0; j--){
            dp[r-1][j] = min(0, dp[r-1][j+1] + A[r-1][j]);
        }
        
        // for all other cells, we check for the max of dps of next cell to the right and next
        // cell to the down, and we add the current cell health requirement, if it is less than zero
        // we keep the value or else we set it to zero
        for(int i = r-2; i >= 0; i--){
            for( int j = c-2; j >= 0; j--){
                dp[i][j] = min(0, max(dp[i+1][j], dp[i][j+1]) + A[i][j]);
            }
        }
        
         //min health is one, so we add it to the abs value of dp[0][0]
        return abs(dp[0][0]) + 1;
    }
};
