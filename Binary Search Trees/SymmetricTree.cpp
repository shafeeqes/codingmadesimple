/*Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric
Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: False
*/

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
bool check(Node* l,Node* r){
    //l - left r-right
    if(!l and !r)
        return true;
    if((!l and r) or(l and !r))
        return false;
    if(l->data == r->data)
        return (check(l->left,r->right)) and (check(l->right,r->left));
    return false;
}

// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
    if(!root)
        return true;
    return check(root->left,root->right);    
}
