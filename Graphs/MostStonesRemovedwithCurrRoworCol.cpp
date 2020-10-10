/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/

class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    
    int removeStones(vector<vector<int>>& stones) {
       
        int n = stones.size();
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        rank.resize(n,0);
        unordered_map<int, int> rows, cols;
        
        for (int k = 0; k < stones.size(); k++) {
            
            int i = stones[k][0], j = stones[k][1];
            
            int parent_i = INT_MAX, parent_j = INT_MAX;
            
            //if curr row already not present in the map, add it
            if (rows.find(i) == rows.end()){
                rows[i] = k;
            }else { //else set row parent of current cell as current row parent
                parent_i = rows[i];
            }
            
            //if curr col not present in the map, add it
            if (cols.find(j) == cols.end()){
                cols[j] = k;
            }else{ //else set col parent of current cell as current col parent
                parent_j = cols[j];
            }
            
            //set parent of k as parent_i
            if (parent_i != INT_MAX) 
                Union(find (parent_i), find(k));
            
            if (parent_j != INT_MAX) 
                Union(find (parent_j), find(k));
        }
        
        unordered_set<int> unique_parents;
        
        for (int k = 0; k < stones.size(); k++) {
            int parent_i = find(k);
            unique_parents.insert(parent_i);
        }
        
        return  n - unique_parents.size();
    }
    
     int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int x, int y){
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else if ( rank[x] > rank[y]){
            parent[y] = x;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
};


