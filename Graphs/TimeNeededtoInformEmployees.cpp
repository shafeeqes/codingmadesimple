/*

A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also it's guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the employees of the company of an urgent piece of news. He will inform his direct subordinates and they will inform their subordinates and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

 

Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.
Example 2:


Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
Example 3:


Input: n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], informTime = [0,6,5,4,3,2,1]
Output: 21
Explanation: The head has id = 6. He will inform employee with id = 5 in 1 minute.
The employee with id = 5 will inform the employee with id = 4 in 2 minutes.
The employee with id = 4 will inform the employee with id = 3 in 3 minutes.
The employee with id = 3 will inform the employee with id = 2 in 4 minutes.
The employee with id = 2 will inform the employee with id = 1 in 5 minutes.
The employee with id = 1 will inform the employee with id = 0 in 6 minutes.
Needed time = 1 + 2 + 3 + 4 + 5 + 6 = 21.
Example 4:

Input: n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
Output: 3
Explanation: The first minute the head will inform employees 1 and 2.
The second minute they will inform employees 3, 4, 5 and 6.
The third minute they will inform the rest of employees.
Example 5:

Input: n = 4, headID = 2, manager = [3,3,-1,2], informTime = [0,0,162,914]
Output: 1076
*/

//dfs

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if (n == 1) return 0;
         unordered_map<int, vector<int>> g; // g == graph
        
        // build the directed graph...
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1) continue;
            g[manager[i]].push_back(i);
        }
        
        return dfs(headID, g, informTime);
    }
    
    int dfs(int curr, unordered_map<int, vector<int>> &g ,vector<int>& informTime){
        
        int maxTime = 0;
            
        for (int nxt : g[curr]){
            maxTime = max(maxTime, dfs(nxt, g,informTime));
        }
        return maxTime + informTime[curr];
    }
};


//Djikstra's algorithm -- really slow

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> time(n , INT_MAX);
        time[headID] = 0;
        
        priority_queue < pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,headID});
        
        unordered_map < int, vector< pair<int,int>>> hash;
        for(int i = 0; i < n; i++){
            if(i == headID) continue;
            hash[manager[i]].push_back({ i, informTime[manager[i]]});
        }
        
        while(!pq.empty()){
            
            pair<int,int> curr = pq.top();
            pq.pop();
            
            int u = curr.second;
            
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
        for(int i = 0; i< n; i++){
            ans = max(ans,time[i]);
        }
            
        return ans == INT_MAX ? -1: ans;
    }
};
