/*
Given a value N, find the number of ways to make change for N cents,
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

â€‹Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the 
function count() which accepts an array S[] its size m and n as input parameter
and returns the number of ways to make change for N cents.



Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n). 


*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        
        int n = coins.size();
	    /*we have to recursively reach target so
        we consider target+1 cols including zero
        and rows are considering 0 elements, then 1, 2
        etc. like [], [1], [1,2], [1,2,3]*/
        vector<vector<int>> dp (n + 1 , vector<int>(amount +1,0));
        
	 /*first column, ways to make zero
         which will be all 1*/
	   
        for(int i = 1; i < n+1; i++){
            dp[i][0] = 1;
        }
	    /*and also first row will all be zeros because we are considering [] , no elements*/
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < amount + 1; j++){
                int curr_coin = coins[i-1];
                if(curr_coin <= j){
		     //total ways is equal to ways to make the difference of current amount and 
		     //current coin with the current coin present + ways to make this amount with present coins already
                    dp[i][j] = dp[i-1][j] + dp[i][j-curr_coin];
                }
		//if curr_coin is greater than current amount then we just skip and take the amount without this coin from above    
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


//alternate solution

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        
        if (amount == 0)
            return 1;
        
        for (int i = 0; i < coins.size(); i++) {
                for (int j = 0; j <= amount; j++) {
                    if (j > coins[i])
                        dp[j] = dp[j - coins[i]] + dp[j];
                    else if (j == coins[i])
                        dp[j] = 1 + dp[j];
                }
        }

        return dp[amount];
    }
};
