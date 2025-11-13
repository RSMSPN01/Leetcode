// Last updated: 11/13/2025, 1:14:33 PM
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
// approach i am thinking is on first traversal i will count the total digits in
// the LL then i will again run a loop from the start and when count becomes
// count/2 or till node->next != null why node->next != null becuase it can fail
// for the edge case when node.value = 2 (try yourself and see)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // if (head->next == nullptr) {
        //     return head;
        // }
        // ListNode* temp = head;
        // int count = 0;
        // while (temp != nullptr) {
        //     count++;
        //     temp = temp->next;
        // }
        // ListNode* temp1 = head;
        // count = count/2;
        // while (temp1->next != nullptr && count) {
        //     temp1 = temp1->next;
        //     count--;
        // }
        // return temp1;
        // intution is this that if we use fast and slow pointer till the time fast reaches end the slow reaches 
        // at the middle because slow only moves half the speed compared to fast pointer
        if(head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};