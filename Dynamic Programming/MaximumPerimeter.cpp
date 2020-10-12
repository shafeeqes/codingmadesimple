//Bargaining Table
//Codeforces 22B
/*
Bob wants to put a new bargaining table in his office. To do so he measured the office room thoroughly and drew its plan: Bob's office room is a rectangular room n × m meters. Each square meter of the room is either occupied by some furniture, or free. A bargaining table is rectangular, and should be placed so, that its sides are parallel to the office walls. Bob doesn't want to change or rearrange anything, that's why all the squares that will be occupied by the table should be initially free. Bob wants the new table to sit as many people as possible, thus its perimeter should be maximal. Help Bob find out the maximum possible perimeter of a bargaining table for his office.

Input
The first line contains 2 space-separated numbers n and m (1 ≤ n, m ≤ 25) — the office room dimensions. Then there follow n lines with m characters 0 or 1 each. 0 stands for a free square meter of the office room. 1 stands for an occupied square meter. It's guaranteed that at least one square meter in the room is free.

Output
Output one number — the maximum possible perimeter of a bargaining table for Bob's office room.

Examples
inputCopy
3 3
000
010
000
outputCopy
8
inputCopy
5 4
1100
0000
0000
0000
0000
outputCopy
16
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[35][35];
int h[35];
//int l[35];
//int r[35];
int output;

//see largest histogram problem in stacks
int maxperimeter(vector<int>& A) {
    
    int n = A.size();
    if(n == 0) return 0;
    if(n == 1 and A[0]==1)
        return 2*(1+1);
    int p;
    stack<int> s;
    int ans = 0;
    int i = 0;
        
    while(i < n)
    {
        if(s.empty() or A[i] >= A[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            int top = s.top();
            s.pop();
             
            if(s.empty()){
                p = 2*(A[top] + i);
                if(A[top] == 0)
                    p = 0;
            }
            else{     
                p = 2 *(A[top] + (i - s.top() - 1));
                if(A[top] == 0)
                    p = 0;
            }
            ans = max(ans,p);
        }
    }
  
    while(!s.empty())
    {
        int top = s.top();
        s.pop();

        if(s.empty()){
            p = 2*(A[top] + i);
            if(A[top] == 0)
                p = 0;
        }
        else{
            p = 2 *(A[top] + (i - s.top() - 1));
            if(A[top] == 0)
                p = 0;
        }
        ans = max(ans,p);
    }
    return ans;
}
void solve(){
    
    int ans = 0;
    vector<int> histogram(m,0);
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '1')
                histogram[j] = 0;
            else if(a[i][j] =='0')
                histogram[j] += 1; 
        }
        ans = max(ans, maxperimeter(histogram));
    }
    output = ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        output=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cont=0;
                int y=i;
                while(1)
                {
                    if(a[y][j]=='0')
                    {
                        cont++;
                        y++;
                        if(y==n)break;
                    }
                    else break;
                }
                h[j]=cont;
            }
            solve();
        }
        printf("%d\n",output);
    }
}
