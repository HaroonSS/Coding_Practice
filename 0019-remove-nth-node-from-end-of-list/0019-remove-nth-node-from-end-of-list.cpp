/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
	int len = 0, i = 1;
	while(curr) 
        curr = curr -> next, len++;    // finding the length of linked list
	if(len == n) 
        return head -> next;           // if head itself is to be deleted, just return head -> next
	for(curr = head; i < len - n; i++) 
        curr = curr -> next;            // iterate first len-n nodes
	curr -> next = curr -> next -> next;      // remove the nth node from the end
	return head;
    }
};
//We just iterate in the first-pass to find the length of the linked list - len.
//In the next pass, iterate len - n - 1 nodes from start and delete the next node (which would be nth node from end).
/*
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *fast = head, *slow = head;
	while(n--) fast = fast -> next;      // iterate first n nodes using fast
	if(!fast) return head -> next;       // if fast is already null, it means we have to delete head itself. So, just return next of head
	while(fast -> next)                  // iterate till fast reaches the last node of list
		fast = fast -> next, slow = slow -> next;            
	slow -> next = slow -> next -> next; // remove the nth node from last
	return head;
}

We are required to remove the nth node from the end of list. For this, we need to traverse N - n nodes from the start of the list, where N is the length of linked list. We can do this in one-pass as follows -

Let's assign two pointers - fast and slow to head. We will first iterate for n nodes from start using the fast pointer.

Now, between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node (which currently is fast)*/