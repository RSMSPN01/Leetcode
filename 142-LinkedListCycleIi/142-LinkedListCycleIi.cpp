// Last updated: 11/13/2025, 1:15:36 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Extended version of the previous problem cycle detection only one thing changes in this we have to find 
 // the starting position which i do now how this works from the floyd's cycle detection method.
 // so i am using that one in this problem too.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=nullptr && fast->next !=nullptr){ // detect the loop first if present
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ // when both came at same place congo! you found a loop
                break;
            }
        }
        if(fast==nullptr || fast->next ==nullptr){
            return nullptr; // it means no cycle is there so return the nullptr
        }
        ListNode *start = head; // so you start a pointer from the start of the LL and also move slow simultaneously
        while(start!=slow){     // is is sure that they will meat at the node from where loop is getting started.
            start = start->next;
            slow = slow->next;
        }
        return slow;
    }
};