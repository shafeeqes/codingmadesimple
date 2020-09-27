/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is
  set of nodes visible when tree is visited from Left side. 
  The task is to complete the function leftView(), which accepts
  root of the tree as argument.

Left view of following tree is 1 2 4 8.

           1
        /    \
     2         3
   /   \     /    \
  4     5   6      7
   \
     8   
  */
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
//Time Complexiy: O(n)
//Space complexity: O(n)
vector<int> leftView(Node *root)
{   
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        for(int i =0; i<size; i++){
            Node *curr = q.front();
            q.pop();
            if(i==0)
                ans.push_back((curr->data));
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}

