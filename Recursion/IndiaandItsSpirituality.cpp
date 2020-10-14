/*
India is well known for its spirituality and holy places, a holy place is represented by '*' (rest of the cities are represented by '.'), and all the cities which are neighbors (which shares a corner or a side) to holy places are known as spiritual cities.

Geek wants to travel all spiritual places, but he decided to travel from one city to another city if both of them are spiritual and neighbors too.

The task is to find the maximum number of spiritual cities geek can travel, starting from a spiritual city.

Note: A holy place is not considered as a spiritual city

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases is as follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines contain M characters

Output: For each test case, print the maximum number of spiritual cities geek can travel.

Your Task:
This is a function problem. You only need to complete the function maxCities() that take a 2-d vector of char, m, n as parameters and returns the maximum number of spiritual cities geek can travel. The driver code automatically appends a new line.

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 102

Example:
Input:
2
5 5
....*
.....
..*..
.....
.....
1 2
**

Output:
10
0

Explanation:
Testcase 1: (1, 4), (2, 2), (2, 3), (2, 4), (2, 5), (3, 2), (3, 4), (4, 2), (4, 3), (4, 4) are the spiritual cities which geek will visit.
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

int maxCities(vector<vector<char>> &a, int n, int m);


// Driver code to test above functions
int main()
{

    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";

    }


    return 0; 
}// } Driver Code Ends


bool issafe(vector<vector<char>> &a,int i,int j,int n,int m){
    if((i>=0)&&(j>=0)&&(i<n)&&(j<m)&&(a[i][j]!='*')) return true;
    return false;
}

vector<int> x{1,1,1,0,0,-1,-1,-1};
vector<int> y{0,1,-1,1,-1,0,1,-1};

void back(vector<vector<char>> &a,int i,int j,int n,int m)
{
    for(int k=0;k<8;k++){
        if(issafe(a,i+x[k],j+y[k],n,m)){
            a[i+x[k]][j+y[k]]='+';
        }
    }
}
int cal(vector<vector<char>> &a,int i,int j,int n,int m)
{
    if((i>=0)&&(j>=0)&&(i<n)&&(j<m)&&(a[i][j]=='+'))
    {
        a[i][j]='.';
        int ans=0;
        for(int k=0;k<8;k++)
        {
            ans+=cal(a,i+x[k],j+y[k],n,m);
        }
        return ans+1;
    }
    return 0;
}
int maxCities(vector<vector<char>> &a, int n, int m)
{
    // Your code goes here
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(a[i][j]=='*')
        back(a,i,j,n,m);
    }
    
    int ans=0,res=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(a[i][j]=='+')
            res = cal(a,i,j,n,m);
        ans=max(res,ans);
    }
    return ans;
}
