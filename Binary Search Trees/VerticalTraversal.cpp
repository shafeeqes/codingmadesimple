//Prob statement
/*Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
     2
      \
       3
      /
     4
Output: 2 4 3

Example 2:

Input:
       1
    /    \
   2      3
 /   \      \
4     5      6

Output: 4 2 1 5 3 6


*/

/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
struct Item{
    Node* node;
    int dist;
    
    public:
    Item(Node* node, int dist){
        this->node = node;
        this->dist = dist;
    }
};
// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Item> q;
    map<int,vector<int>> vertical;
    
    q.push(Item(root,0));
    
    while(!q.empty()){
        Item currItem = q.front();
        q.pop();
        Node* curr = currItem.node;
        int dist = currItem.dist;
        vertical[dist].push_back(curr->data);
        if(curr->left){
            q.push(Item(curr->left,dist-1));
        }
        if(curr->right){
            q.push(Item(curr->right,dist+1));
        }
    }
    
    for(auto m:vertical){
        vector<int> vertical_vector = m.second;
        for(int elem:vertical_vector){
            ans.push_back(elem);
        }
    }
    return ans;
}

/*
There is a similar problem Binary Tree Vertical Order Traversal, which is different from this problem only in the following requirement.

If two nodes are in the same row and column, the order should be from left to right.

In this problem, if two nodes are in the same row and column, the order should be from small to large.

The idea is to build a mapping from coordinates to nodes.
*/
BFS

Build the mapping using a queue of pairs of nodes and corresponding coordinates.

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
DFS

Build the mapping recursively.

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        traverse(root, 0, 0, nodes);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
private:
    void traverse(TreeNode* root, int x, int y, map<int, map<int, set<int>>>& nodes) {
        if (root) {
            nodes[x][y].insert(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};
