/*
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes the existence of a bidirectional path from garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

There is no garden that has more than three paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Constraints:

1 <= n <= 104
0 <= paths.length <= 2 * 104
paths[i].length == 2
1 <= xi, yi <= n
xi != yi
No garden has four or more paths coming into or leaving it.

*/

class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> colors (n+1 ,-1);
        vector<vector<int>> graph (n+1);
        
        for(auto edge:paths){
            int v1 = edge[0];
            int v2 = edge[1];
            
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
         for(int node = 1; node <= n; node++)
         {
             vector<int> used(5, 0);   
             //if already color assigned, continue
             if(colors[node] > 0)
                 continue;
             
             //check all the edges, mark those colors as used
             for(auto edge: graph[node])
             {
                 if (colors[edge] > 0)
                     used[colors[edge]] = 1;
             }
             
             //assign the color which is not used
             for (int k = 1; k < 5; k++)
             {   
                 if (!used[k]) 
                    colors[node] = k;
             }
        }
        //delete the first element. we are returning 0 based
        colors.erase(colors.begin());
        return colors;
    }
   
    
};
