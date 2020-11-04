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
        
        dp[r-1][c-1] = A[r-1][c-1] <= 0 ? A[r-1][c-1]: 0;
        
        for(int i = r-2; i >= 0; i--){
            int reqPower = dp[i+1][c-1] + A[i][c-1];
            if( reqPower <= 0){
                dp[i][c-1] = reqPower;
            }
            else{
                dp[i][c-1] = 0;
            }
        }
        
        for(int j = c-2; j >= 0; j--){
            int reqPower = dp[r-1][j+1] + A[r-1][j];
            if( reqPower <= 0){
                dp[r-1][j] = reqPower;
            }
            else{
                dp[r-1][j] = 0;
            }
        }
        
        for(int i = r-2; i >= 0; i--){
            for( int j = c-2; j >= 0; j--){
                int reqPower =  max(dp[i+1][j], dp[i][j+1]) + A[i][j];
                if( reqPower <= 0){
                    dp[i][j] = reqPower;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return abs(dp[0][0]) + 1;
    }
};
