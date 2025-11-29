// Last updated: 11/29/2025, 10:28:47 PM
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
// I am not getting any approach in my mind instead i will love to start from
// the naive way so i will take an vector, sotre the values at there and then
// reverse that and again push back to the linked list other approach i am
// thinking is how we do this same problem in the arrays in the arrays we just
// have to rotate the array 3 times to get to the result iykyk... but to apply
// here the same approach, is kind of hard
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr) {
            return head;
        }
        vector<int> v;
        ListNode* temp = head;
        while (temp != nullptr) {
            v.push_back(temp->val); // store the values of LL in the vector
            temp = temp->next;
        }
        if (k != v.size()) { // rotate the vector by k steps
            for (int i = 0; i < v.size(); i += k) {
                if (i + k <= v.size()) {
                    reverse(v.begin() + i, v.begin() + i + k);
                }
            }
        } else { // if same then just rotate the whole LL in once and return it.
            reverse(v.begin(), v.end());
        }
        ListNode* temp1 = head;
        for (int i = 0; i < v.size(); i++) { // again push back to the LL
            temp1->val = v[i];
            temp1 = temp1->next;
        }
        return head;
    }
};