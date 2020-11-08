/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum. You can move in 4 directions : up, down, left an right.

Note : It is assumed that negative cost cycles do not exist in input matrix.

Input:
The first line of input will contain number of testcases T. Then T test cases follow. Each test case
contains 2 lines. The first line of each test case contains an integer N denoting the size of the grid.
Next line of each test contains a single line containing N*N space separated integers depicting the cost
of respective cell from (0,0) to (N,N).

Output:
For each test case output a single integer depecting the minimum cost to reach the destination.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= grid[i][j] <= 104

Example:
Input:
2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14

Output:
327
63

Explanation:
Testcase 1:
Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20
A cost grid is given in below diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)
*/

//Dsjikstra's Algorithm

//using pair<int,int> for a cell

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int directions[4][4] = {{+1,0}, {-1,0}, {0,+1}, {0,-1}};

int solve(vector<vector<int>> &A){
    int n = A.size();
    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
    vector<vector<bool>> processed(n, vector<bool> (n,false));
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    //push starting node
    pq.push({A[0][0], {0,0}});
    dist[0][0] = A[0][0];

    while(!pq.empty()){
        
        int curr_dist = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        
        pq.pop();
        //keep track of processed nodes
        processed[i][j] = true;
                
        for(int k = 0; k < 4; k++){
            int nextI = i + directions[k][0];
            int nextJ = j + directions[k][1];
            
            //relax cells in all four dir
            if(nextI >=0 and nextI < n and nextJ >=0 and 
                        nextJ < n and !processed[nextI][nextJ]){
                if(curr_dist + A[nextI][nextJ] < dist[nextI][nextJ]){
                    dist[nextI][nextJ] = curr_dist + A[nextI][nextJ];
                    pq.push({dist[nextI][nextJ], {nextI,nextJ}});
                }
            }
        }
    }
    
    return dist[n-1][n-1];    
}
int main() {
	//code
	int t;
	cin >>t;
	while(t--){
    	int N;
    	cin>>N;
    	vector<vector<int>> A(N, vector<int>(N));

    	for(int i = 0; i < N; i++){
    	    for(int j = 0; j < N; j++){
    	        cin>>A[i][j];
    	    }
    	}
    	cout<<solve(A)<<endl;
	}
	return 0;
}




//Using  struct cell

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int directions[4][4] = {{+1,0}, {-1,0}, {0,+1}, {0,-1}};
struct cell 
{ 
    int x, y; 
    //int d; 
    cell(int x, int y){ 
        this->x = x;
        this->y = y;
        //this->d = d;
    }
}; 

bool operator < (const cell &a, const cell &b){
    
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int solve(vector<vector<int>> &A){
    int n = A.size();
    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
    vector<vector<bool>> processed(n, vector<bool> (n,false));
    
    priority_queue<pair<int,cell>, vector<pair<int,cell>>, greater<pair<int,cell>>> pq;
    pq.push({A[0][0], cell(0,0)});
    dist[0][0] = A[0][0];

    while(!pq.empty()){
        
        int curr_dist = pq.top().first;
        cell curr_cell = pq.top().second;
        pq.pop();

        int i = curr_cell.x;
        int j = curr_cell.y;
        processed[i][j] = true;
                
        for(int k = 0; k < 4; k++){
            int nextI = i + directions[k][0];
            int nextJ = j + directions[k][1];
            
            if(nextI >=0 and nextI < n and nextJ >=0 and 
                        nextJ < n and !processed[nextI][nextJ]){
                if(curr_dist + A[nextI][nextJ] < dist[nextI][nextJ]){
                    dist[nextI][nextJ] = curr_dist + A[nextI][nextJ];
                    pq.push({dist[nextI][nextJ], cell(nextI,nextJ)});
                }
            }
        }
    }
    
    return dist[n-1][n-1];    
}
int main() {
	//code
	int t;
	cin >>t;
	while(t--){
    	int N;
    	cin>>N;
    	vector<vector<int>> A(N, vector<int>(N));

    	for(int i = 0; i < N; i++){
    	    for(int j = 0; j < N; j++){
    	        cin>>A[i][j];
    	    }
    	}
    	cout<<solve(A)<<endl;
	}
	return 0;
}
