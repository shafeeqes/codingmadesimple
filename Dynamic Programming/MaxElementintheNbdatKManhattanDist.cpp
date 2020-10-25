/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
*/
//O(n*n*k)

vector<vector<int> > Solution::solve(int k, vector<vector<int> > &M) {
    
    vector<vector<int>> ans(M);
    int r = M.size();
    if(r < 1)   return ans;
    int c = M[0].size();
    
    while(k--){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i-1 >= 0 and M[i-1][j] > ans[i][j])
                    ans[i][j] = M[i-1][j];
                if(j-1 >= 0 and M[i][j-1] > ans[i][j])
                    ans[i][j] = M[i][j-1];
                if(i+1 < r and M[i+1][j] > ans[i][j])
                    ans[i][j] = M[i+1][j];
                if(j+1 < c and M[i][j+1] > ans[i][j])
                    ans[i][j] = M[i][j+1];
            }
        }
        M = ans;
    }
    
    return ans;
}
