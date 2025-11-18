// Last updated: 11/18/2025, 10:01:34 AM
/*
 * This is the naive approach to solve the problem it requires two traversals of the node. it is not efficient approach.
 * TC = O(n + k). and constant space complexity.
*/

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
// 1st naive approach is to traverse and count the total no. of nodes = n; TC =
// O(n + n) two traversals then traverse the node till n-k where k is node to
// remove

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        if(count==n){ // it means we have to delete the first node.
            return head->next;
        }
        int result = count - n -1; // here n-k nodes to traverse till the node to remove.
        ListNode* temp1 = head;
        while (result != 0) {
            temp1 = temp1->next;
            result--;
        }
        temp1->next = temp1->next->next;
        return head;
    }
};