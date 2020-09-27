/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
The diagram below shows two trees each with diameter nine, the leaves that form the ends of a 
longest path are shaded (note that there is more than one path in each tree of length nine, 
but no path longer than nine nodes).

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
*/
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int depth(Node* node){
    if (!node)
        return 0;
    return max(depth(node->right),depth(node->left))+1;    
}
void max_dia(Node* root, int &maxdia){
    if(!root)
        return;
    int dia = depth(root->left)+depth(root->right)+1;
    maxdia = max(maxdia,dia);
    max_dia(root->left,maxdia);
    max_dia(root->right,maxdia);
}
int diameter(Node* root) {

    if(!root)
        return 0;
    int maxdia = INT_MIN;
    max_dia(root,maxdia,);
        
    return maxdia;
}
