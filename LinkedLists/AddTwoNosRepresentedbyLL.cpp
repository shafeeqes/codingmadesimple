/*
Given two numbers represented by two linked lists of size N and M. The task is to 
return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both 
the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000
*/

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    stack<Node*> s1,s2;
    Node* curr1 = first, *curr2 = second;
    while(curr1){
        s1.push(curr1);
        curr1 = curr1->next;
    }
    while(curr2){
        s2.push(curr2);
        curr2= curr2->next;
    }
    int carry = 0, sum = 0;
    Node* tailnode = NULL;
    Node* curr;
    while(!s1.empty() and !s2.empty()){
        int n1 = s1.top()->data;
        int n2 = s2.top()->data;
        
        sum = n1+n2+carry;
        carry = 0;
        if(sum > 9){
            carry = 1;
            sum %= 10;
        }
        curr = new Node(sum);
        curr->next = tailnode;
        tailnode = curr;
        s1.pop(); s2.pop();
    }
    while(!s1.empty()){
        int n1 = s1.top()->data;
        sum = n1+carry;
        carry = 0;
        if(sum > 9){
            carry = 1;
            sum %= 10;
        }
        curr = new Node(sum);
        curr->next = tailnode;
        tailnode = curr;
        s1.pop();
    }
    while(!s2.empty()){
        int n2 = s2.top()->data;
        sum = n2+carry;
        carry = 0;
        if(sum > 9){
            carry = 1;
            sum %= 10;
        }
        curr = new Node(sum);
        curr->next = tailnode;
        tailnode = curr;
        s2.pop();
    }
    if(carry == 1){
        curr = new Node(1);
        curr ->next = tailnode;
    }
    return curr;
}
