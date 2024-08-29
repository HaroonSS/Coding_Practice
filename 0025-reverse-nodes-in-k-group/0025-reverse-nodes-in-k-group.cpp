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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        int c =0;
        while(c < k){
            if(curr == NULL) 
                return head;
            
            curr = curr->next;
            c++;
        }
        
        int count = 0;
        ListNode* prev = NULL, *next = NULL;
        curr = head;
        
        while(curr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next){
            head->next = reverseKGroup(next, k);
        }
        
        return prev;  
    }
};