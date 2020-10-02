/*
Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Example 2:

Input:
Q = 4
Queries = 1 2 2 2 1 3 
Output: 2 -1
Explanation: In the second testcase 
1 2 the queue will be {2}
2   poped element will be {2} then
    the queue will be empty. 
2   the queue is empty and hence -1
1 3 the queue will be {3}.
Your Task:
Complete the function push() which takes an integer as input parameter and 
pop() which will remove and return an element(-1 if queue is empty).

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if(!rear)
        front = rear = newNode;
    else{
      rear->next = newNode;
      rear = newNode;
    }
        
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if(front == NULL)  return -1;
    int value = front->data;
    QueueNode *prevfront = front;
    front = front->next;
    if(front == NULL)  
        rear=NULL;
    delete prevfront;
    return value;
}