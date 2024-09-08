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
        
        if(head == NULL){
            return 0;
        }
        int len = 1, count = 0;
        ListNode* curr = head, *lastNode;
        
        while(curr->next){
            len++;
            curr = curr->next;
        }
        lastNode = curr;
        
         if(len <= k){
             k = k % len;
         }
        
        k = len - k;
        curr = head;
        while(count < k-1 && curr){
            count++;
            curr = curr->next;
        }
        
        lastNode->next = head;
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
        
    }
};