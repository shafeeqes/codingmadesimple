  
/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is
  set of nodes visible when tree is visited from Left side. 
  The task is to complete the function rightView(), which accepts
  root of the tree as argument.
Left view of following tree is 1 3 7 8.
           1
        /    \
     2         3
   /   \     /    \
  4     5   6      7
   \
     8   
  */

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  */

//Time Complexiy: O(n)
//Space complexity: O(n)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i =0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
                if(i==0)
                    ans.push_back((curr->val));
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
        return ans;
    }
};
