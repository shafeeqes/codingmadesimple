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
