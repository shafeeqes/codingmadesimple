/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.


Example 1:

Input :      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          

Output: 16

Explanation :
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

Example 2:

Input :    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  

Output :  27

Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

Your Task:  
You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.
*/
/*
struct Node
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
int sumPath(Node* node){
    if(!node)
        return 0;
     //the following conditions are required because
     //if 0 is returned for a null path and negative is 
      //returned for a valid path. it'll take zero
    if(!node->right)
        return sumPath(node->left)+node->data;
    if(!node->left)
        return sumPath(node->right) + node->data;
    return max(sumPath(node->right),sumPath(node->left))+node->data;
}
void path_Sum(Node* node,int& maxSum){
    if(!node)
        return;
    if(!node->right or !node->left) //if node is not a leaf node
        return;
    int pathSum = sumPath(node->left) + sumPath(node->right) + node->data;
    maxSum = max(maxSum,pathSum);
    path_Sum(node->right,maxSum);
    path_Sum(node->left,maxSum);
}

int maxPathSum(Node* root)
{ 
   if(!root)
    return 0;
   int maxSum = INT_MIN;
   path_Sum(root,maxSum); 
   return maxSum;
}
