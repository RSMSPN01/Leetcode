/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // The naive approach is to store the node address and check if it is already there in the table
 // or not if not then insert it if already there then return the val respective to the node.
 // Efficient approach.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;
        while(temp1!=nullptr){
            s.insert(temp1); // first insert all the nodes of 1st LL
            temp1 = temp1->next;
        }
        while(temp2!=nullptr){
            if(s.find(temp2) != s.end()){ // if found then return from here else 
                return temp2;
            }
            s.insert(temp2); // keep pushing the nodes into the list.
            temp2 = temp2->next;
        }
        return nullptr;
    }
};