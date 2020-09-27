
void connect(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> p;
    p.push(root);
    root->nextRight = NULL;
    
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
        while(!c.empty()){
            Node *curr = c.front();
            c.pop();
            if(!c.empty()){
                curr->nextRight = c.front();
            }
            else
                curr->nextRight = NULL;
        }
    }
}
