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
