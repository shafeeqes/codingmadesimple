/*

Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return a list of tree nodes representing the generated BST's.
Constraints:

1 <= A <= 15
Example:

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
   */
   
   
   
   /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  function for constructing trees 
vector<TreeNode*> constructTrees(int start, int end) 
{ 
    vector<TreeNode*> list; 
  
    /*  if start > end   then subtree will be empty so returning NULL 
        in the list */
    if (start > end) 
    { 
        list.push_back(NULL); 
        return list; 
    } 
  
    /*  iterating through all values from start to end  for constructing\ 
        left and right subtree recursively  */
    for (int i = start; i <= end; i++) 
    { 
        /*  constructing left subtree   */
        vector<TreeNode*> leftSubtree  = constructTrees(start, i - 1); 
  
        /*  constructing right subtree  */
        vector<TreeNode*> rightSubtree = constructTrees(i + 1, end); 
  
        /*  now looping through all left and right subtrees and connecting 
            them to ith root  below  */
        for (int j = 0; j < leftSubtree.size(); j++) 
        { 
            for (int k = 0; k < rightSubtree.size(); k++) 
            { 
                TreeNode* left = leftSubtree[j]; 
                TreeNode* right = rightSubtree[k]; 
                TreeNode* node = new TreeNode(i);// making value i as root 
                node->left = left;              // connect left subtree 
                node->right = right;            // connect right subtree 
                list.push_back(node);           // add this tree to list 
            } 
        } 
    } 
    return list; 
} 
  
 
vector<TreeNode*> Solution::generateTrees(int A) {
   
    return constructTrees(1, A);  
}
