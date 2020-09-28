/*
Given a Binary Search Tree (with all values unique) and two node values. 
Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the 
function LCA() which takes the root Node of the BST and two integer values
n1 and n2 as inputs and returns the Lowest Common 
Ancestor of the Nodes with values n1 and n2 in the given BST. 
*/
/*
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

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
Node* LCA(Node *root, int n1, int n2)
{
    int rootval = root->data;
    if(n1>rootval and n2>rootval){
        return LCA(root->right,n1,n2);
    }
    else if(n1<rootval and n2<rootval){
        return LCA(root->left,n1,n2);
    }
    else return root;
}
