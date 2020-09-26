//Problem Statement
//Given a binary tree. Check whether it is a BST or not.
  
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

#include<bits/stdc++.h>
bool isSubTreeLesser(Node* root,int value){
    if (root == NULL)
        return true;
    //All the values in all the subtrees should be less than value
    if(root->data <= value and
            isSubTreeLesser(root->right,value) and
            isSubTreeLesser(root->left,value))
        return true;
    return false;    
}
bool isSubTreeGreater(Node* root,int value){
    
    if (root == NULL)
        return true;
    //All the values in all the subtrees should be more than value
    if(root->data > value and
            isSubTreeGreater(root->right,value) and
            isSubTreeGreater(root->left,value))
        return true;
    
    return false; 
}
bool isBST(Node* root){
    // Your code here
    if(root==NULL)
        return true;
    // Any tree which satisfies all the following 4 conditions are BST    
    if(isBST(root->right) and isBST(root->left)
        and isSubTreeLesser(root->left,root->data) 
        and isSubTreeGreater(root->right,root->data))
        return true;
    
    return false;    
}
