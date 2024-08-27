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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: If the head is null or there's nothing to reverse
        if (!head || left == right) return head;

        // Dummy node to handle edge cases where reversing starts from the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move `prev` to the node just before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // `start` will point to the first node to be reversed
        ListNode* start = prev->next;
        // `then` will point to the node that will be reversed
        ListNode* then = start->next;

        // Step 2: Reverse the sublist from `left` to `right`
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        // Step 3: Return the head of the modified list
        return dummy->next;
        
    }
};