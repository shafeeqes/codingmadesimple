/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.
*/
/* A binary tree node structure

struct Node
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

bool isBalanced(Node* root) {
    
    if(!root)
        return true;
    if (!root->left and !root->right)
        return true;
    //if one is null and other is not then the not null 
    //one should not have further childs
    if(!root->left and root->right)
        if(root->right->right or root->right->left)
            return false;
    if(!root->right and root->left)
        if(root->left->right or root->left->left)
            return false;
    //if both right and left present
    return isBalanced(root->left) and isBalanced(root->right);
}
