/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:  5 10 39 1

        1
     /     \
   10     39
  /
5

Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19

Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11
Your Task:
You don't need to read input or print anything. Your task is to complete
the function postOrder() that takes root node as input and returns an array
containing the postorder traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
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

vector <int> postOrder(Node* root)
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
            curr = curr->left;
            if(curr){
                s.push(curr);
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        else{
            s.push(curr);
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }while(!s.empty());
    
    reverse(ans.begin(),ans.end());
    return ans;
}
