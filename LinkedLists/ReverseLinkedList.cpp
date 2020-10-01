/*
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
*/

/* Linked List Node structure:
struct Node
{
    int data;
    struct Node *next;
}
*/
// Should reverse list and return new head.
Node* reverseList(Node *head)
{
    if(!head)
        return head;
    Node *curr =head, *prev =NULL, *next;
    
    while(curr){
        next = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


//Alternate solution:

#include<bits/stdc++.h>

Node* reverseList(Node *head)
{
    if(!head)
        return head;
    stack<Node*> s;
    Node* curr = head;
    while(curr){
        s.push(curr);
        curr = curr->next;
    }
    if(!s.empty()){
        head = s.top();
        s.pop();
        curr = head;
    }
    while(!s.empty()){
        curr->next = s.top();
        s.pop();
        curr= curr->next;
    }
    curr->next= NULL;
    return head;
}

