/*

In a directed graph, we start at some node and every turn, walk along a directed edge of the graph. 
If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.
More specifically, there exists a natural number K so that for any choice of where to walk, we must have 
stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is
given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

*/

class Solution {
public:
   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();

 		vector<int>res;
 		vector<int>dp(V, 0);

 		for (int i = 0; i < V; i++) {    
 			if (dfs(graph, i, dp))
 				res.push_back(i);
 		}

 		return res;
        
    }
    
    bool dfs(vector<vector<int>>& graph, int v, vector<int>& dp){
        
        // we dont want to get caught in an infinite loop
        if (dp[v])
 			return dp[v] == 1;
        
       //dont want to visit this node again during the dfs
        dp[v] = -1;
        
        //if it is already a terminal node, then this loop wont be entered
        // we return true. so if any of the paths is not safe from the current 
        // vertex, we return false
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
 			if (!dfs(graph, *it, dp))
 				return false;

 		dp[v] = 1;

 		return true;
    }
};
