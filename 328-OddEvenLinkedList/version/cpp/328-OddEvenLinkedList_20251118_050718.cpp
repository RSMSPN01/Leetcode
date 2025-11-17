// Last updated: 11/18/2025, 5:07:18 AM
// Naive approach to solve the problem by storing the nodes address in freq array and then changing the links.
/**
 * Definition for singly-linked list.
 * struct ListNode {=
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// the very first approach which is to store the address of the odd and even
// nodes in two different arrays and then merge them together it is O(n+n) tc
// and O(n) sc for sure

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        // make the temp array to store the address of the nodes.
        vector<ListNode*> even;
        vector<ListNode*> odd;
        ListNode* temp1 = head;       // odd index pointer
        ListNode* temp2 = head->next; // even pointer
        while (temp2 != nullptr) {
            if(temp2->next == nullptr){
                odd.push_back(temp1);
                even.push_back(temp2);
                break;
            }
            if(temp2->next->next == nullptr){
                even.push_back(temp2);
                odd.push_back(temp1);
                odd.push_back(temp1->next->next);
                break;
            }
            odd.push_back(temp1);
            even.push_back(temp2);
            temp1 = temp1->next->next;
            temp2 = temp2->next->next; // This is the main error trying to acess the null->next->next.
        }
        ListNode *temp = head;
        for (int i = 1; i < odd.size(); i++) {
            temp->next = odd[i];
            temp = temp->next;
        }
        for (int i = 0; i < even.size(); i++) {
            temp->next = even[i];
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};