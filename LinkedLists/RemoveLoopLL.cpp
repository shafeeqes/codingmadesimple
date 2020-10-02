/*
You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 

Note: C is the position of the node to which the last node is connected. If it is 0 then no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
C = 2
Output: 1
Explanation: In the first test case
N = 3.The linked list with nodes
N = 3 is given. Here, x = 2 which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop. 

Example 2:
Input:
N = 4
value[] = {1,8,3,4}
C = 0
Output: 1
Explanation: N = 4 and x = 0, which
means lastNode->next = NULL, thus
the Linked list does not contains
any loop.
Your Task:
Your task is to complete the function removeLoop(). The only argument of the function is 
head pointer of the linked list. Simply remove the loop in the list (if present) without 
disconnecting any nodes from the list. The driver code will print 1 if your code is correct.

Expected time complexity : O(n)

Expected auxiliary space : O(1)
*/
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>
void removeLoop(Node* head)
{
    Node* curr = head;
    unordered_set<Node*> s;
    Node *prev = NULL;
    while(curr){
        if(s.find(curr)!=s.end()){
            prev->next = NULL;
            return;
        }
        s.insert(curr);
        prev = curr;
        curr = curr->next;
    }
    return;
}


//Alternate solution

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>
void removeLoophelper(struct Node* loop_node, struct Node* head) 
{ 
    struct Node* ptr1 = loop_node; 
    struct Node* ptr2 = loop_node; 
  
    // Count the number of nodes in loop 
    unsigned int k = 1, i; 
    while (ptr1->next != ptr2) { 
        ptr1 = ptr1->next; 
        k++; 
    } 
  
    // Fix one pointer to head 
    ptr1 = head; 
  
    // And the other pointer to k nodes after head 
    ptr2 = head; 
    for (i = 0; i < k; i++) 
        ptr2 = ptr2->next; 
  
    /*  Move both pointers at the same pace, 
      they will meet at loop starting node */
    while (ptr2 != ptr1) { 
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    } 
  
    // Get pointer to the last node 
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 
  
    /* Set the next node of the loop ending node 
      to fix the loop */
    ptr2->next = NULL; 
} 
 
void removeLoop(Node* head)
{
    Node *slow = head, *fast = head;
    while(slow and fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            removeLoophelper(slow,head);
            return;
        }
    }
    return;
}
