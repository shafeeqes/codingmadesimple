/*
Complete the function to find spiral order traversal of a tree.  
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which returns the elements in spiral form 
of level order traversal as a list. The newline is automatically appended by the driver code.
*/
/*
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

vector<int> findSpiral(Node *root)
{
     vector<int> ans;
    if(root == NULL)
        return ans;
    queue<Node*> p;
    p.push(root);
    ans.push_back(root->data);
    //left to right
    int dir = 1;
    
    while(!p.empty()){
        int size = p.size();
        //Only iterate upto the current size. 
        //so only current elements will be traversed.
        for(int i =0; i<size; i++){
            Node *curr = p.front();
            p.pop();
            if(curr->left)
                p.push(curr->left);
            if(curr->right)
                p.push(curr->right);
        }
        queue<Node*> c = p;
        if(dir == 1){
            while(!c.empty()){
                ans.push_back(c.front()->data);
                c.pop();
            }
        }
        else{ //dir = 0 right to left
        //we reverse the elements using stack
            stack<int> s;
            while(!c.empty()){
                s.push(c.front()->data);
                c.pop();
            }
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        dir = (dir+1)%2;
    }
    return ans;
}
