"""
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        curr = head
        prev = None
        nxt = None
        i = 0
        
        ## ignore this block if we want to reverse even if at the end
        # number of elements is less than k
        temp = head
        size = 0
        while temp:
            size += 1
            temp = temp.next
        if size < k:
            return head
        
        while curr and i<k:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            i += 1
        
        if nxt:
            head.next = self.reverseKGroup(nxt,k)
        return prev
