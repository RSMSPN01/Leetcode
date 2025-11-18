// Last updated: 11/18/2025, 2:46:51 PM
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