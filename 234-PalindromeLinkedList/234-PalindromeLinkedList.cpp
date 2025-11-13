// Last updated: 11/13/2025, 1:15:18 PM
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
// approacher i was thinking of
// 1>so i was thinking of the two pointer approach here but i realize that there
// is no way to traverse back the LL 2> using fast and slow pointer but there is
// no point of reaching the middle when we can't traverse back 3> using extra
// space store the values in an vector run a loop from back and check each value
// O(n+n), O(n); 4>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // brute force \\ naive way
        vector<int> v;
        ListNode* temp = head;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int j = v.size() - 1;
        ListNode* temp2 = head;
        while (j >= 0) {
            if (temp2->val != v[j]) {
                return false;
            }
            temp2 = temp2->next;
            j--;
        }
        return true;
    }
};