/*
Given a binary tree, find its preorder traversal.

Example 1:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 
Example 2:

Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root
node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N)
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

vector <int> preorder(Node* root)
{
    stack<Node*> s;
    vector<int> ans;
    if(!root)
        return ans;
    Node* curr = root;
    
    do{
        if(curr==NULL){
            curr = s.top();
            s.pop();
            curr = curr->right;
            if(curr){
                s.push(curr);
                ans.push_back(curr->data);
                curr = curr->left;
            }
        }
        else{
            s.push(curr);
            ans.push_back(curr->data);
            curr = curr->left;
        }
    }while(!s.empty());
    
    return ans;
}
