// Last updated: 11/18/2025, 12:17:39 PM
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
// another approach is break the problem into small problem and then solve it
// try of 3 nodes first what is actually happening there and then move to next
// approach try to thinking of some jumping node in which you are jumping from
// one node to another node.
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = even->next;
            even->next = even->next->next;
            even = odd->next;
        }
        odd->next = evenHead;
        return head;
        // this is my approach of solving the problem the code works fine for
        // the odd lenght LL for even you to take another variable to check the
        // length of the LL which makes the code hard to understand so i am
        // using the most optimal way to write the code. ListNode* curr = head;
        // ListNode* secnd = head->next; // stores the second node to connect at
        // the last after traversing the LL ListNode* temp = nullptr; int count
        // = 1; while (curr->next != nullptr) {
        //     temp = curr->next; // sotres the next node
        //     curr->next = curr->next->next;
        //     count++;
        //     if(curr->next->next == nullptr){
        //         if(count&1){
        //             curr = temp;
        //         }else{
        //             // it can be solve using this too but its is very hard to
        //             understand the code.
        //         }
        //         break;
        //     }
        //     curr = temp;
        // }
        // temp->next = secnd;
        // return head;

        // It is the most basic approach you can think of it works in traversing
        // link list once O(n) then traversing the odd array and then even array
        // O(n+n) and space is also O(n+m); this is the very naive approach

        // if (head == nullptr || head->next == nullptr || head->next->next ==
        // nullptr) {
        //     return head;
        // }
        // // make the temp array to store the address of the nodes.
        // vector<ListNode*> even;
        // vector<ListNode*> odd;
        // ListNode* temp1 = head;       // odd index pointer
        // ListNode* temp2 = head->next; // even pointer
        // while (temp2 != nullptr) {
        //     if(temp2->next == nullptr){
        //         odd.push_back(temp1);
        //         even.push_back(temp2);
        //         break;
        //     }
        //     if(temp2->next->next == nullptr){
        //         even.push_back(temp2);
        //         odd.push_back(temp1);
        //         odd.push_back(temp1->next->next);
        //         break;
        //     }
        //     odd.push_back(temp1);
        //     even.push_back(temp2);
        //     temp1 = temp1->next->next;
        //     temp2 = temp2->next->next; // This is the main error trying to
        //     acess the null->next->next.
        // }
        // ListNode *temp = head;
        // for (int i = 1; i < odd.size(); i++) {
        //     temp->next = odd[i];
        //     temp = temp->next;
        // }
        // for (int i = 0; i < even.size(); i++) {
        //     temp->next = even[i];
        //     temp = temp->next;
        // }
        // temp->next = nullptr;
        // return head;
    }
};