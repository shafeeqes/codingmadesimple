/*

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> m;
    
    queue <UndirectedGraphNode *> q;
    q.push(node);
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
    
    m[node] = newNode;
    
    while(!q.empty()){
        
        UndirectedGraphNode * current = q.front();
        q.pop();
        
        vector<UndirectedGraphNode *> v = current->neighbors;
        
        for(int i=0; i<v.size();i++){
            if(m[v[i]] == NULL){
                UndirectedGraphNode* temp = new UndirectedGraphNode(v[i]->label);
                m[v[i]] = temp;
                q.push(v[i]);
            }
            //push clone of neighbour node to neighbour list of clone of current node
            m[current]->neighbors.push_back(m[v[i]]);
        }
    }
    
    return newNode;
}
