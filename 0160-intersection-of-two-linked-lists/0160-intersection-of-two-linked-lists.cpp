/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curr1 = headA;
    ListNode* curr2 = headB;
    
    while(curr1 != curr2) {
        curr1 = (curr1 == NULL) ? headB: curr1->next;
        curr2 = (curr2 == NULL) ? headA: curr2->next;
    }
    
    return curr1;
        
    }
};/*
Any time they collide or reach end together without colliding then return any one of the pointers.

If one of them reaches the end earlier then reuse it by moving it to the beginning of other list.
Once both of them go through reassigning, they will be equidistant from the collision point.


        
ListA = A + intersection
ListB = B + intersection
with this solution, it's like we concat ListA and ListB then find the intersection.
ListA+ListB = A + intersection + B +intersection
ListB + ListA = B + intersection + A + intersection
Then we can find the intersections.
    
finally i understand.
ListA+ListB = A + intersection + B + (will meet here) intersection
ListB + ListA = B + intersection + A +(will meet here)intersection*/