/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

*/


// https://leetcode.com/problems/possible-bipartition/

/*
    Question : Bipartition is possible or not.

    Solution 1: Using two HashMap/HashSet such that no two person dislike each other are in same group.
    It is very easy ti implement so i will not going to code it.

    Solution 2: Using BFS 

    We can do something similiar like solution 1 using graph as well. What we will do ? 
    we will choose two color as two set means assume all vertices in graph which has marked 0 are in 
    one set, and which were marked as 1 in another set.

    Now there shouldn't two adjacent vertex have same color. If two adjacent vertex have same color then
    we will return false, else return true.

    Now to divide a graph in such a manner is known as Bipartite Graph. It is a graph having even number of edges
    such that there will be no edge between two vertices, which were in same set.

    Time Complexity - O(V + E)
*/

class Solution {
public:
    vector<int> color;
    vector<vector<int>> graph;
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        graph.resize(N+1);
        
        // Color(1 & 0 are two color) & Initialize with -1(Colorless)
        color.resize(N+1, -1);
        
        // Build a Undirected graph. Undirected Graph Why ?
        // Because if (a,b) a dislikes b is equivalent to b dislikes a.
        for(auto edge:dislikes){
            int v1 = edge[0];
            int v2 = edge[1];
            
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        for(int node = 1; node <= N; node++)
        {
            // If it is colorless, then color it and check if 
            //two adjacent vertex have same color then return false
            if(color[node] == -1)
            {
                if(!check(node))
                    return false;
            }
        }
        return true;
        
    }
    bool check(int node){
        
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            //nb- neighbour
            for(int nb: graph[curr])
            {
                // Two adjacent vertex have same color
                if(color[nb] == color[curr])
                {
                    return false;
                }
                if(color[nb] == -1)
                {
                    // If it is colorless, then color it with different color as parent node
                    color[nb] = 1 - color[curr];
                    q.push(nb);
                }
            }
        }
        
        return true;
    }
};





