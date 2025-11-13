// Last updated: 11/13/2025, 1:15:17 PM
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
    void deleteNode(ListNode* node) {
        // if(node->next = NULL){  // if it was the last element then use this.
        //     node = NULL;
        // }
        // The way i was thinking the question is this i want to free the memory space(delete) of the node
        // And i need to connect the previous address with the next address.
        // but in the question it is given that we don't have to remove it from the memory.
        // so you can basically overwrite that as well.
        ListNode* temp = node->next;
        while (temp->next != NULL) {
            node->val = temp->val;
            node = temp;
            temp = temp->next;
        }
        node->val = temp->val;
        node->next = NULL;
        delete temp;
    }
};