/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2

Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


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

vector<int> levelOrder(Node* root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Node*> p;
    p.push(root);
    ans.push_back(root->data);
    
    while(!p.empty()){
        int size = p.size();
        //Only iterate upto the current size. 
        //so only current elements will be traversed.
        for(int i =0; i<size; i++){
            Node *curr = p.front();
            p.pop();
            if(curr->left)
                p.push(curr->left);
            if(curr->right)
                p.push(curr->right);
        }
        queue<Node*> c = p;
        while(!c.empty()){
            ans.push_back(c.front()->data);
            c.pop();
        }
    }
    return ans;

}
