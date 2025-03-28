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
    ListNode* sortList(ListNode* head) {

        vector<int> list; 

        while(head) {
            list.push_back(head->val);
            head = head->next;

        }

        sort(list.begin(), list.end());

        ListNode* parentNode = new ListNode(-1);
        ListNode* temp = parentNode;

        for (auto node: list){
            temp->next = new ListNode(node);
            temp = temp->next;
        }

        return parentNode->next;
        
    }
};