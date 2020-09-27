/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
 
 //O(1) space. much easier O(H) space solution in the bottom
class Solution {
public:
    void flatten(TreeNode* root) 
    { 
        // base condition- return if root is NULL 
        // or if it is a leaf node 
        if (root == NULL || root->left == NULL && 
                            root->right == NULL) { 
            return; 
        } 
         // if root->left exists then we have  
        // to make it root->right 
        if (root->left != NULL) { 

            // move left recursively 
            flatten(root->left); 

            // store the node root->right 
            TreeNode* tmpRight = root->right; 
            root->right = root->left; 
            root->left = NULL; 

            // find the position to insert 
            // the stored value    
            TreeNode* t = root->right; 
            while (t->right != NULL) { 
                t = t->right; 
            } 

            // insert the stored value 
            t->right = tmpRight; 
        } 

        // now call the same function 
        // for root->right 
        flatten(root->right); 
    } 
  
};


//Alternate solution

void flatten(TreeNode* root) {
        if (!root){
            return;
        }
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty()){
			//Preorder traversal 
            TreeNode* curr = s.top();
            s.pop();
            
            if (curr->right){
                s.push(curr->right);
            }
            if (curr->left){
                s.push(curr->left);
            }
            if(!s.empty()){
                curr->right = s.top();
            }
            curr->left = NULL;
        }
    }
};
