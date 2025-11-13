// Last updated: 11/13/2025, 1:15:24 PM
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
 // 1st approach is definately storing the values into the container but it take two traversals and extra space too.
 // The mistake i was doing is that i was trying to think in the opposite way of the appraoch 
 // 1->2->3->null what i was doing i was trying to store the value of 3 (temp->next->next) which makes the code
 // complex and even nearly impossible to traverse becuase it breaks the LL in two part 1st> 2->1->null and 2nd>
 // is 3->null now i have to traverse two different LL.
 // but in the approach i was storing the current address as an intution that i am only changing one link just 
 // reversing the links so the current node becomes my previous node itself.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode *temp = head;
        while(temp!=nullptr){
            ListNode* nextAddress = temp->next; //stored the next address.
            temp->next = prev; // store the prev value 
            prev = temp; // update the prev value to the current value
            head = temp; // update the value of the head to its new head.
            temp = nextAddress; // now move the temp to the next address.
        }
        return head;
    }
};