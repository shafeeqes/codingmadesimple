//Prob Statement
/*Given a binary tree, print the top view from left to right.
A node is included in top view if it can be seen when we look at the tree from top.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the top view is 5 8 20 22 25.
*/
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

struct Item{
    Node* node;
    int dist;
    Item(Node* node,int dist){
        this->node = node;
        this->dist = dist;
    }
    Item(){
        
    }
};
vector <int> bottomView(Node *root)
{
    map<int,vector<int>> m;
    queue<Item> q;
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    Item currItem; 
    q.push(Item(root,0));
    Node* curr;
    int dist;
    while(!q.empty()){
        currItem = q.front();
        q.pop();
        curr = currItem.node;
        dist = currItem.dist;
        m[dist].push_back(curr->data);
        if(curr->left)
            q.push(Item(curr->left,dist-1));
        if(curr->right)
            q.push(Item(curr->right,dist+1));
    }
    for(auto element:m){
        int dis = element.first;
        vector<int> values = element.second;
        int n = values.size();
        //Top view
        //ans.push_back(values[0]);
    }
    return ans;
}
