// Last updated: 11/18/2025, 2:56:02 PM
// This is the most efficient approach to solve the problem it is as same as the easy question there is not even a single difference between both of them it should be an easy question to be solve.
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
 // 1st approach : Use two pointer approach of one and two steps i beleive it is the most fastest way to solve the 
 // problem then i will look for other better approaches 
 // I am thinking in the right direction though the approach worked as expected we have to create a temp node
 // to store the node before the middle node to directly point it to the next node of middle.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){ 
            prev = slow;
            slow = slow->next; // it will reach in the middle of the LL
            fast= fast->next->next;
        }
        prev->next = prev->next->next; // change the address of the Linked List to point it directly to the next of next.
        return head;
    }
};