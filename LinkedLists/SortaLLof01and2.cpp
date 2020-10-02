/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to 
head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the 
linked list as asked in the problem statement and returns the head of the modified 
linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* Merge(Node* A, Node* B)  
{  
    Node *result;
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    if(A->data <= B->data){
        result = A;
        result->next = Merge(A->next,B);
    }
    else{
        result = B;
        result->next = Merge(A,B->next);
    }
    return result;
}  
Node* segregate(Node *head) {
    
    if(!head or !head->next){
        return head;
    }
    
    Node* curr = head;
    head = head->next;
    curr->next = NULL;
    return Merge(curr,segregate(head));
    
}


/*/Alternate solution

Traverse the lisr and keep count of 0,1,2
Traverse again and replace the LL values with this*/

//ANother solution:


// Sort a linked list of 0s, 1s and 2s 
// by changing pointers. 
Node* sortList(Node* head) 
{ 
    if (!head || !(head->next)) 
        return head; 
  
    // Create three dummy nodes to point to 
    // beginning of three linked lists. These 
    // dummy nodes are created to avoid many 
    // null checks. 
    Node* zeroD = newNode(0); 
    Node* oneD = newNode(0); 
    Node* twoD = newNode(0); 
  
    // Initialize current pointers for three 
    // lists and whole list. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    // Traverse list 
    Node* curr = head; 
    while (curr) { 
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        } else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    // Attach three lists 
    zero->next = (oneD->next)  
? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    // Updated head 
    head = zeroD->next; 
  
    // Delete dummy nodes 
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head; 
} 
