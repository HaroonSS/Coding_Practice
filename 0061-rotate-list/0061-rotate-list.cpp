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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Edge cases

        // Step 1: Find the length of the list and the last node
        ListNode* curr = head;
        int len = 1; // List length starts at 1
        while (curr->next) {
            len++;
            curr = curr->next;
        }
        ListNode* lastNode = curr; // The last node of the list

        // Step 2: Calculate the effective rotations needed
        k = k % len;
        if (k == 0) return head; // No rotation needed

        // Step 3: Find the new head (after len - k steps) and tail (len - k - 1 steps)
        int stepsToNewHead = len - k;
        curr = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            curr = curr->next;
        }

        // Step 4: Perform the rotation
        ListNode* newHead = curr->next;
        curr->next = NULL;        // Break the list
        lastNode->next = head;    // Connect last node to old head

        return newHead;
    }
};
