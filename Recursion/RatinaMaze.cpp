/*
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the
destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source
to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at 
a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.
Example 2:
Input: N = 2, m[][] = {{1, 0},
                       {1, 0}}
Output: -1
Explanation: No path exits

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which 
takes N and 2d array m[][] as input parameters and returns a sorted list of paths.
 
Note:  In case of no path, return an empty list. The driver will output -1 automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.

*/


// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int directions[4][4] = {{+1,0},{-1,0},{0,+1},{0,-1}};
char dir[] = {'D','U','R','L'};

void back(int m[MAX][MAX], int n, int i, int j, string temp, 
             vector<vector<bool>> &visited, vector<string>&ans){
    
    if(i < 0 or i>= n or j < 0 or j>=n or m[i][j] == 0 or visited[i][j])
        return;
    if( i == n-1 and j == n-1){
        ans.push_back(temp);
        return;
    }
    
    visited[i][j] = true;
    for(int k = 0; k < 4; k++){
        int nextI = i + directions[k][0];
        int nextJ = j + directions[k][1];
        //saving current progress
        string backup = temp;
        temp += dir[k];
        back(m,n,nextI,nextJ,temp,visited,ans);
        //undoing last change
        temp = backup;
    }
    visited[i][j] = false;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<string> ans;
    string temp = "";
    back(m,n,0,0,temp,visited,ans);
    sort(ans.begin(),ans.end());
    return ans;
    
}

