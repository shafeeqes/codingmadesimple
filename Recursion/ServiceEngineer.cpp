/*

https://i.imgur.com/5I9Nq5c.png
https://i.imgur.com/fAVGjZG.png
https://i.imgur.com/bPQPMVS.png

*/

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;
int minlen=INT_MAX;
vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp,int cnt,int path)
{
    if(grid[i][j] && cnt==1) {
        minlen=min(minlen,path);
        return;
    }
    if(grid[i][j]) cnt--;
    
    
    int val=grid[i][j];
    grid[i][j]=-1;
    
    for(int k=0;k<4;k++)
    {
        int r=i+dir[k][0];
        int c=j+dir[k][1];
        
        if(r>=0 && c>=0 && r<n && c<m && grid[r][c]!=-1)
            dfs(r,c,n,m,grid,dp,cnt,path+1);
    }
    grid[i][j]=val;

}
int finddays(int n,int m,vector<vector<int>> &grid)
{
    int cnt=0,val=0;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            val=val+grid[i][j];
            if(grid[i][j]!=0) {
                cnt++;
            }
    }
    dfs(0,0,n,m,grid,dp,cnt,0);
        return val+2*minlen;
}
int main()
{
   int n,x;
   vector<vector<int>> grid={{3,0,3,0},{3,0,0,3},{0,0,5,0}};
    cout<<"\n"<<finddays(3,4,grid)<<endl;
   
   return 0;
}
