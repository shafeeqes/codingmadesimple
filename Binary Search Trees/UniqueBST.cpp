//Catalan Number


/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19

*/

class Solution 
{
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1, 0);
        // if no nodes or one node, only one combination
        dp[0] = 1; 
        dp[1] = 1;
        
        //calculating numTrees for all numbers up to n
        for(int i = 2;i <= n; i++)
        {
            //considering each number before i as root and adding total combination of both sides    
            for(int j = 1;j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
};




class Solution 
{
public:
    //catalan number
    int numTrees(int n) 
    {
        if (n == 1)
            return 1;
        
		//avoid overflow
        long long over = (long long)numTrees(n-1)*(4*n-2)/(n+1);
        
        return (int)over;
    }
};


/*
 # numTree[4] = numTree[0] * numTree[3] +
        #              numTree[1] * numTree[2] +
        #              numTree[2] * numTree[1] +
        #              numTree[3] * numTree[0]
       */
       
       
