/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        
        for(auto prerequisite: prerequisites)
        {
            int course = prerequisite[0];
            int pre_course = prerequisite[1];
            
            graph[pre_course].push_back(course);
        }
        
        vector<bool> visited (n, false);
        stack<int> s;
        
        if(detectCycle(graph,n))
            return false;
        
        return true;
    }
    //Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util( vector<vector<int>>& graph, vector<int>& visited,int v)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   //Mark current as visited
        for(int i = 0; i < graph[v].size(); ++i)
            if(detectCycle_util(graph, visited, graph[v][i]))
                return true;
        
        visited[v]=2;   //Mark current node as processed
        return false;
    }
    
    //Cycle detection
    bool detectCycle(vector<vector<int>>& graph,int n)
    {
        vector<int> visited(n,0);
        for(int i = 0; i < n ;++i)
            if(!visited[i])
                if(detectCycle_util(graph, visited, i))
                    return true;
        return false;
    }
};
