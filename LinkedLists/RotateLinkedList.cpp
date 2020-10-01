/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
Explanation:
Example 2:

Input:
N = 5
value[] = {2,4,7,8,9}
k = 3
Output: 8 9 2 4 7
Explanation:
Your Task:
The task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= k <= 103*/

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k)
{
    if (k == 0) 
        return head; 
    int count = 1;
    Node* curr = head;
   
    while(count<k && curr){
        curr = curr->next;
        count++;
    }
    //if length  = k
    if(!curr->next)   return head;
    Node *kthNode = curr;
    
    while(curr->next){
        curr = curr->next;
    }
    curr->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}
