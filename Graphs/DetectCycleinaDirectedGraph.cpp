/*
Given a Directed Graph. Check whether it contains any cycle or not.

Input: The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' 
test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First 
line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges 
respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is an uni-directed  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
You don't need to read input or print anything. Your task is to complete the function isCyclic which takes 
the Graph and the number of vertices and inputs and returns true if the given directed graph contains a cycle. Else, it returns false.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 1000
1<= N,M <= 1000
0 <= u,v <= N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1

Explanation:
Testcase 1: In the above graph there are 2 vertices. The edges are as such among the vertices.


From graph it is clear that it contains cycle.

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool helper(vector<int> graph[], vector<int> &visited, int node)
{
	// 0- not processed, 1 - processing , 2- processed
	//here unlike undirected graph, where when we encounter a processed node and we return true
	//here we return true when a currently processing node is enocuntered
    if(visited[node] == 1)
        return true;
    
    if(visited[node] == 2)
        return false;
        
    visited[node] = 1;
    for(int i = 0; i< graph[node].size();++i)
    {   int curr = graph[node][i];
        if(helper(graph, visited, curr))
            return true;
    }
    visited[node] = 2;
    return false;
}

bool isCyclic(int V, vector<int> graph[]){
    
    vector<int> visited(V,0);
    
    for(int i = 0;i < V; ++i){
        if(!visited[i]){
            if(helper(graph, visited, i))
                return true;
        }            
    }
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends



//similar solution


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool helper(vector<int> graph[], vector<bool> &visited, int node)
{
    if(visited[node]==true)
        return true;
    
    visited[node] = true;
 
    for(int i = 0; i< graph[node].size();++i)
    {   int curr = graph[node][i];
        if(helper(graph, visited, curr))
            return true;
    }
    visited[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> graph[]){
    
    vector<bool> visited(V,false);
    
    for(int i = 0;i < V; ++i){
        visited[i] = true;
        for(int j = 0;j < graph[i].size();++j){
            int curr = graph[i][j];
            if(helper(graph, visited, curr))
                return true;
        }
        visited[i] = false;
    }
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
