/*
Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.
Your Task:
You need to complete the function flatten() that takes head of the list as 
parameter and returns the root of flattened list. The printing is done by the driver code.

Note: Try to solve the problem without using any extra space.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};
*/
Node* merge(Node* A,Node* B){
    if(!A)  return B;
    if(!B)  return A;
    Node* result;
    if(A->data<=B->data){
        result = A;
        result->bottom = merge(A->bottom,B);
    }
    else{
        result=B;
        result->bottom = merge(A,B->bottom);
    }
    return result;
}
Node *flatten(Node *root)
{
   if(!root or !root->next) return root;
   
   return merge(root,flatten(root->next));
   
}
