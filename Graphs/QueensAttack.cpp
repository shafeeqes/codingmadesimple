/*
On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. 
Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

Notes:

Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity is worst case O(N*M).
For example,

Let chessboard be,
[0 1 0]
[1 0 0]
[0 0 1]

where a 1 denotes a queen at that position.

Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
and so on...

Finally, we return matrix
[3, 1, 2]
[1, 3, 3]
[2, 3, 0]
*/


void helper(int curr_row, int curr_col, vector<string> &A, 
            vector<vector<int>> &ans,int n, int m){
    
    int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    //Go in all directions. update all the cells by 1.
    //if we find another queen in the same direction
    //update that queen's col (we can attack her) and break
    for(int k = 0; k < 8; k ++){
        
        int i = curr_row + x[k], j = curr_col +y[k];
   
        while(i >= 0 and j >= 0 and i < n and j < m){
            if(A[i][j] == '1'){
                ans[i][j]++;
                break;
            }
            else
                ans[i][j]++; 
            
            i += x[k];
            j += y[k];
        }
    }
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    
    int n = A.size();
    vector<vector<int>> ans;
    if (n < 1)
        return ans;
    int m = A[0].size();
    
    ans.resize(n, vector<int> (m,0));
    
    vector<pair<int,int>> queens;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] =='1'){
                helper(i, j, A, ans, n, m);
            }
        }
    }
    
    return ans;
}
