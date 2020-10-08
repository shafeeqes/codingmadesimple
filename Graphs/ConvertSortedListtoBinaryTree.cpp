/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3
   
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//not really required . already TreeNode constructor present 
/*TreeNode* newNode(int data){
    TreeNode* root = new TreeNode(data);
    root->right = root-> left = NULL;
    return root;
}*/
TreeNode* createBST(ListNode* head){
    
    TreeNode* temp1 = NULL;
    if(head == NULL)
        return temp1;
    
    ListNode* current = head;
    vector<ListNode*> list;
    while(current){
        list.push_back(current);
        current= current->next;
    }
    int n = list.size(),rootval;

    if(n==1){
        return new TreeNode(head->val);
    }
    
    vector<ListNode*> v1, v2;
    for(int i = 0; i < n; i++)
    {
        if(i <= (n/2-1)) v1.push_back(list[i]);
        else if (i == n/2) rootval = list[i]->val;
        else v2.push_back(list[i]);
    }
       
    ListNode* temp2 = NULL;
    if(v1.empty())
        v1.push_back(temp2);
    if(v2.empty())
        v2.push_back(temp2);    
    
    v1[v1.size()-1]->next = NULL;
    
    TreeNode* root;
    root = new TreeNode(rootval);
    
    root->left = createBST(v1[0]);
    root->right = createBST(v2[0]);
    
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return createBST(A);
}
