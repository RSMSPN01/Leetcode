// Last updated: 11/26/2025, 10:38:07 AM
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
// my approach is simple use two loops add them one by one and store in the new
// linked list as simple as that i am thinking this so only thing which needs to
// be keep in the mind is to handle the cases well where there is no data or the
// length is not same.

// this question is mainly to check how well you have the basics knowledge of
// the LL's.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(); // new LL is created here
        ListNode* temp1 = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) { // traverse till both becomes null.
            int data1 = 0 ,data2 = 0;
            if (l1 !=nullptr) { // checking edge case for uneven length of LL's.
                data1 = l1->val; // value of 1st LL taken here
                l1 = l1->next;
            }else{
                data1 = 0; // is out of bound then take zero.
            }
            if (l2 != nullptr) {
                data2 = l2->val; // value of second LL is taken here.
                l2 = l2->next;
            }else{
                data2 = 0;
            }
            temp1->next = new ListNode((data1 + data2 + carry)%10); // here new node is created
            temp1 = temp1->next;
            if ((data1 + data2 + carry) > 9) { // we check carry after the pushing the value in LL
                carry = 1;          // because we will add the currn carry in next calculation.
            } else {
                carry = 0;
            }
        }
        if(carry){
            temp1->next = new ListNode(1);
        }
        return head->next;
    }
};