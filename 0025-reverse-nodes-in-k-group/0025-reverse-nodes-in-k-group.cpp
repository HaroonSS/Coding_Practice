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
    bool isValid(ListNode* temp, int k){
        int c = 0;
        while(temp){
            temp = temp->next;
            c++;
            
            if(c >= k){
                return true;
            }
        }
        
        return false;  
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count = 0;
        ListNode* prev = NULL, *next = NULL, *curr = head;
        
        while(curr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next){
            head->next = isValid(next, k) ? reverseKGroup(next, k): next;
        }
        
        return prev;  
    }
};