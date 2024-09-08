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
    void reorderList(ListNode* head) {
       vector<ListNode*> arr;
        ListNode* curr = head;
        while(curr){
            arr.push_back(curr);
            curr = curr->next;
        }
            
        
		// pointers to start and end of list. Re-order in alternating fashion from both end
        int L = 1, R = arr.size() -1;
        for(int i = 1; i < arr.size(); i++){
            if(i%2 == 1)                             // odd iteration:
                head -> next = arr[R--];          //        - pick node from L & update L ptr
            else                                  // even iteration
                head -> next = arr[L++];          //        - pick node from R & update R ptr
            
            head = head -> next;
        }
        
        head -> next = NULL;
        
    }
};
/*
2-Pointers using Extra Space)

We can solve this question easily if using extra space is allowed. The re-ordering arrangement basically consist of 1st node, then last node, then 2nd node, then 2nd last node and so on till all nodes are covered. Thus, we just put one node from the start, then one from end in an alternating fashion. In this approach -

We first use an auxillary array to store the nodes of linked-list
Once the array is filled, we initialize two variables L and R which denotes the current positions on the two ends from which we need to re-order the list in alternate fashion
In odd iteration, we assign the next node as arr[L] and move the L pointer ahead
In even iteration, we assign the next node as arr[R] and move the R pointer backward
This will re-order the list as alternating nodes from start and end as required.*/