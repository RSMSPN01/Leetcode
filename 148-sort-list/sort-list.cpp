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
 // 1st approach the naive way just store the values in the vector, sort it and then add the values back to it
 // TC = O(nlogn + n+ n) and SC = O(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode * temp = head;
        vector<int>v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        ListNode *temp2 = head;
        int i = 0;
        while(temp2!=nullptr){
            temp2->val = v[i];
            i++;
            temp2 = temp2->next;
        }
        return head;
    }
};