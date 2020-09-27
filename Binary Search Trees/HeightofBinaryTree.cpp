//Problem Statement
//Given the root node , find the height of the node ie; the height of the tree
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

int height(Node* root)
{
    if(root == NULL)
        return 0;
    else return max(height(root->left),height(root->right))+1;
}
