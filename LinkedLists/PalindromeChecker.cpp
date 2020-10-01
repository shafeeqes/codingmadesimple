/*
Given a singly linked list of size N of integers. The task is to check
if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only 
parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

Node* ptr;
bool helper(Node* head){
    
    if(head->next == NULL){
        return ptr->data == head->data;
    }
    if (helper(head->next)){
        ptr = ptr->next;
        return ptr->data == head->data;
    }
    
}
bool isPalindrome(Node *head)
{
    if (!head)
        return true;
    ptr = head;    
    return helper(head);
        
}


//Alternate solution


bool isPalindrome(Node *head)
{
    if (!head)
        return true;
    
    stack<Node*> s;
    Node* curr1 = head,*curr2;
    while(curr1){
        s.push(curr1);
        curr1 = curr1->next;
    }
    curr1 = head;
    while(!s.empty()){
        curr2 = s.top();
        if(curr1->data != curr2->data)
            return false;
        curr1 = curr1->next;
        s.pop();
    }
    return true;    
}
