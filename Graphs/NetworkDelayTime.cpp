/*

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

*/

//Djikstra's algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        priority_queue < pair<int,int>, vector< pair<int,int> >, greater<pair<int,int>>> pq;
        // push source node with time 0
        pq.push({0,K});
        
        vector<int> time(N+1, INT_MAX);
        time [K] = 0;
        
        unordered_map < int, vector <pair<int,int>>> hash;
        
        for(int i = 0; i < times.size(); i++){
            hash[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        while(!pq.empty()){
            
            pair<int,int> curr_v= pq.top();
            pq.pop();
            
            int u = curr_v.second;
            
            for(auto it = hash[u].begin(); it!= hash[u].end(); it++){
                int v = it->first;
                int wt = it->second;
                
                if(time[u] + wt < time[v]){
                    time[v] = time[u] + wt;
                    pq.push({time[v],v});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i < N+1; i++){
            if(time[i]>ans)
                ans = time[i];
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


//Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        int E = times.size();
        if(!E)
            return 0;
        vector<int> time(N+1,INT_MAX);
        
        time[K] = 0;
        bool updated = false;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < E; j++){
                int u = times[j][0];
                int v = times[j][1];
                int wt = times[j][2];
                
                if(time[u]!= INT_MAX and time[u] + wt < time[v]){
                    time[v] = time[u] + wt;
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <=N; i++){
            if(time[i] > ans)
                ans = time[i];
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
