/*
Given a Binary Tree of size N ,

You have to count leaves in it. For example, there are two leaves in following tree

        1
     /      \
   10      39
  /
5

Input:
First line of input contains the number of test cases T. For each test case
, there will be only a single line of input which is a string representing 
the tree as described below: 

The values in the string are in the order of level order traversal of the
tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case print the count of leaves.
Your Task:

You don't have to take input. Complete the function countLeaves() that takes root
node of given tree as parameter and returns the count of leaves in tree . 
The printing is done by the driver code.
*/
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
void helper(Node* root,int &count){
    if(!root)
        return;
    if(!root->right and !root->left)
        count++;
    helper(root->right,count);
    helper(root->left,count);
}   
int countLeaves(Node* root)
{
    int count = 0;
    if(!root)
        return 0;
    helper(root,count);
    return count;
}
