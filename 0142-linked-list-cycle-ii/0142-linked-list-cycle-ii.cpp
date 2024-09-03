/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;

           	// Phase 1: Detect the loop
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;	// Move slow one step

                fast = fast->next->next;	// Move fast two steps

               	// If slow and fast meet, a loop is detected
                if (slow == fast)
                {
                    slow = head;	// Reset the slow pointer to the head of the list

                   	// Phase 2: Find the first node of the loop
                    while (slow != fast)
                    {
                       	// Move slow and fast one step at a time
                        slow = slow->next;
                        fast = fast->next;
                       	// When slow and fast meet again, it's the first node of the loop
                    }
                    return slow;	// Return the first node of the loop
                }
            }
           	// If no loop is found, return NULL
            return NULL;
        }
};/*https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
Step 2: If there is a cycle, return the entry location of the cycle

2.1) L1 is defined as the distance between the head point and entry point
2.2) L2 is defined as the distance between the entry point and the meeting point
2.3) C is defined as the length of the cycle
2.4) n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer

According to the definition of L1, L2 and C, we can obtain:

the total distance of the slow pointer traveled when encounter is L1 + L2
the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C
Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:
2 * (L1+L2) = L1 + L2 + n * C 
L1 + L2 = n * C
L1 = (n - 1) C + (C - L2)*
It can be concluded that the distance between the head location and entry location is equal to the distance between the meeting location and the entry location along the direction of forward movement.*/