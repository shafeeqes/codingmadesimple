/*
Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
       1
     /  \
    3    2
Output: 3 1 2

Example 2:

Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function inOrder() that takes
root node of the tree as input and returns a list containing
the In-Order Traversal of the given Binary Tree.*/

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */


// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root)
{   
    stack<Node*> s;
    vector<int> ans;
    if(root == NULL)
        return ans;
    Node* curr = root;
    
    do{
        if(curr==NULL){
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
            if(curr){
                s.push(curr);
                curr = curr->left;
            }
        }
        else{
            s.push(curr);
            curr = curr->left;
        }
    }while(!s.empty());
    
    return ans;
}
