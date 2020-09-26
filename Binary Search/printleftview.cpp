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
#include<bits/stdc++.h>
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root == NULL)
    return ans;
    
    ans.push_back(root->data);
    Node *curr = root->left;
    while(curr){
        ans.push_back((curr->data));
        if(curr->left)
            curr = curr->left;
        else          
            //if left is null go right
            curr= curr->right;
    }
    
    return ans;
}

