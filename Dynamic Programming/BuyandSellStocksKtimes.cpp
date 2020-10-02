/*
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/



int Solution::solve(vector<int> &A, int k) {
    
    int n = A.size();
    if(n<2) return 0;
    k = min(k,n);
    vector<vector<int> > T(k+1, vector<int>(n,0));
    
    for(int i=1;i<T.size();i++){
        int prevdiff = INT_MIN;
        for(int j=1;j<T[0].size();j++){
            prevdiff= max(prevdiff,T[i-1][j-1]-A[j-1]);
            T[i][j] = max(T[i][j-1],A[j]+prevdiff);
        }
    }       
    return T[k][n-1];
    
}


/*

T[i][j] = max( T[i][j-1],  // Not transacting on jth day.
              T[i-1][m] + price[j] - price[m] m = 0....j-1 //best you can get by transacting on j-1th day.
              
this can be written as T[i][j] = max(T[i][j-1], A[j] + prevdiff) //so we can save on an inner loop
                                  prevdiff = max(prevdiff, T[i-1][j-1] - A[j-1])
*/
