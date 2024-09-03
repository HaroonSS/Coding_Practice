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
};