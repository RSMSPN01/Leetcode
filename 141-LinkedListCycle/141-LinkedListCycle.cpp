// Last updated: 11/13/2025, 1:15:38 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// approach i am thinking which i learned in array is floyd's cycle detection in
// array
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==nullptr){
            return false;
        }
        if(head->next == nullptr){
            return false;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (slow != fast && fast!=nullptr && fast->next !=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast) {
            return true;
        }
        return false;
    }
};