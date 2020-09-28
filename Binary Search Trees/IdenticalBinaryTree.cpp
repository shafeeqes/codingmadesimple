/*

Given two binary trees, the task is to find if both of them are identical or not. 

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3.
Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: No
Explanation: There are two trees both
having 3 nodes and 2 edges, but both
trees are not identical.
Your task:
Since this is a functional problem you don't have to worry 
about input, you just have to complete the function isIdentical() 
that takes two roots as parameters and returns true or false. 
The printing is done by the driver code.
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

/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 and !r2)
        return true;
    if((!r1 and r2) or(r1 and !r2) or r1->data!= r2->data)
        return false;
    
    if(!isIdentical(r1->right,r2->right) or !isIdentical(r1->left,r2->left))
        return false;
        
    return true;
        
}
//Alternate almost similar

 bool isIdentical(TreeNode* r1, TreeNode*r2){
        if(!r1 or !r2){
            return !r1 and !r2;
        } else if(r1->val==r2->val){
            return isIdentical(r1->right,r2->right) and isIdentical(r1->left,r2->left);
        }
        return false;
    }

//Similar approach

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* rootA, TreeNode* rootB) {
    
    if(rootA==NULL && rootB == NULL)
        return 1;
    if(rootA==NULL && rootB!=NULL)
        return 0;
    if(rootB==NULL && rootA!=NULL)
        return 0;
    
    if(rootA->val != rootB->val)
        return 0;
    else return min(isSameTree(rootA->left,rootB->left),isSameTree(rootA->right,rootB->right));
    
}
