/*

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your 
task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

*/

class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<pair<int,int>>> graph(n);
        vector<int> dist(n, INT_MAX);
    
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int pathcost = flight[2];
            graph[u].push_back({v,pathcost});
        }
    
        queue<pair<int,int>> q;
        
        q.push({src, 0});
        dist[src] = 0;
        // normal BFS traversal
        k++;
        while( k--){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int u = q.front().first;
                //note: we are using the prev pushed distance
                //not dist[u] at present, because while relaxing some
                //edges, this dist[u] can change and mess up the answer
                int d = q.front().second;
                q.pop();
            
                // traverse for the neighbors of u
                for(auto x : graph[u]){
                    // x = {v, wt}
                    int v = x.first;
                    int wt = x.second;
                    if(dist[v] > d + wt){
                        dist[v] = d + wt;
                        q.push({v,dist[v]});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? -1: dist[dst];
    }
    
    
};

//much slower
class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> cost;
    int minCost = INT_MAX;
    vector<bool> visited;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        graph.resize(n);
        cost.resize(n + 1, vector<int> (n+1));
        
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int pathcost = flight[2];
            graph[u].push_back(v);
            cost[u][v] = pathcost;
        } 
        visited.resize(n, false);
        dfs(0, src, dst, K, -1, visited);
        return minCost == INT_MAX ? -1: minCost;
    }
    
    void dfs(int curr_cost, int curr, int dest, int K, int stops, vector<bool> &visited){
        
        if(curr_cost > minCost){
            return;
        }
        if(curr == dest){
            minCost = min(minCost, curr_cost);
        }
        if(stops == K){
            return;
        }
        
        visited[curr] = true;
        for(int i = 0; i < graph[curr].size(); i++){
            int v = graph[curr][i];
            if(visited[v])
                continue;
            int pathcost = cost[curr][v];
            dfs(curr_cost + pathcost, v, dest, K, stops + 1, visited);
        }
        visited[curr] = false;
    }
    
};
