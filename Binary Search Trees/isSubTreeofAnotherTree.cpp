/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isIdentical(TreeNode* r1, TreeNode*r2){
        if(!r1 and !r2)
            return true;
        if((!r1 and r2) or(r1 and !r2) or r1->val!= r2->val)
            return false;
           if(!isIdentical(r1->right,r2->right) or !isIdentical(r1->left,r2->left))
            return false;
        
        return true;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s and !t)
            return true;
        if((!s and t) or (s and !t))
                return false;
        return isIdentical(s,t) or isSubtree(s->right,t) or isSubtree(s->left,t);
    }
};


//Alternate , almost similar
class Solution {
public:
    bool isIdentical(TreeNode* r1, TreeNode*r2){
        if(!r1 or !r2){
            return !r1 and !r2;
        } else if(r1->val==r2->val){
            return isIdentical(r1->right,r2->right) and isIdentical(r1->left,r2->left);
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s)
            return false;
        else if(isIdentical(s,t)){
            return true;
        } 
        return isSubtree(s->right,t) or isSubtree(s->left,t);
    }
};
