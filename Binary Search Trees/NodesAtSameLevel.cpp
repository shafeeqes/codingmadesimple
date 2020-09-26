//Problem Statement
/*Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL
*/

/* struct Node
{
  int data;
  Node *left, *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

//THE SAME CODE CAN BE USED FOR LEVEL ORDER TRAVERSAL

// O(n) space
//O(n) time

void connect(Node *root)
{
    queue<Node*> parent, children;
    if(root == NULL)
        return;
    parent.push(root);
    root->nextRight = NULL;
    Node* curr;
    
    while(true){
        while(!parent.empty()){

            curr = parent.front();
            parent.pop();
            if(curr->left)
                children.push(curr->left);
            if(curr->right )
                children.push(curr->right);
        }
        if(children.empty())
            return;
        parent = children;
        
        while(!children.empty()){
            
            curr = children.front();
            children.pop();
            if(!children.empty())
                curr->nextRight = children.front();
            else
                curr->nextRight = NULL;
        }
    }
}



//If in the question it is given it is a perfect BST, then 
void connect(Node *root)
{
    queue<Node*> parent, children;
    if(root == NULL)
        return;
    parent.push(root);
    root->nextRight = NULL;
    Node* curr;
    
    while(true){
        while(!parent.empty()){

            curr = parent.front();
            parent.pop();
            if(curr->left and current->right){
                children.push(curr->left);
                children.push(curr->right);
            }
          else 
              return;
        }
        parent = children;
        
        while(!children.empty()){
            
            curr = children.front();
            children.pop();
            if(!children.empty())
                curr->nextRight = children.front();
            else
                curr->nextRight = NULL;
        }
    }
}
