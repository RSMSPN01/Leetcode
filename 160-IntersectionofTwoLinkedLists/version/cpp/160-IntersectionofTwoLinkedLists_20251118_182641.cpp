// Last updated: 11/18/2025, 6:26:41 PM
// Naive way to solve the approach
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
 // TC = O(n+m) SC = O(n).
 // Efficient approach. - not working because we can't modify the values of the string
 // The same we use to check in inplace checking in array if we have already visited the index
 // either we store it or we marked the values as -1 if we have already visited that.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode*temp1 = headA;
        // ListNode*temp2 = headB;

        // This is efficient but we can't modify the values so yeah not working.... ):
        // while(temp1!=nullptr){
        //     // mark the values as -1 because we have visited them once.
        //     temp1->val = -1;
        //     temp1 = temp1->next;
        // }
        // while(temp2!=nullptr){
        //     if(temp2->val <0){
        //         return temp2;
        //     }
        //     temp2 = temp2->next;
        // }
        // return nullptr;


        //Navie approach using extra space.
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