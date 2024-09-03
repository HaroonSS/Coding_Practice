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
    bool isPalindrome(ListNode* head) {
        ListNode *curr = head;
        vector<int> v;
        
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int left =0, right = v.size()-1;
        
        while(left < right){
            if(v[left] != v[right])
                return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};