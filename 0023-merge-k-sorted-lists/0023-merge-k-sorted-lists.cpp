// Approach : Although this question is from heap but i do have the idea about
// solving this problem though which i did using recursion not by heap not lets
// try heap too
class Solution {
public:
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        // this will merge two list without creating extra space
        ListNode* newList = new ListNode(-1);
        ListNode* temp = newList;
        ListNode* first = list1;
        ListNode* second = list2;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                ListNode* nextNode = first->next;
                temp->next = first;
                first->next = nullptr;
                temp = first;
                first = nextNode;
            } else {
                ListNode* nextNode = second->next;
                temp->next = second;
                second->next = nullptr;
                temp = second;
                second = nextNode;
            }
        }
        if (first != nullptr) {
            temp->next = first;
        }
        if (second != nullptr) {
            temp->next = second;
        }
        return newList->next;
    }
    ListNode* helper(int i, vector<ListNode*>& lists) {
        // recursively merging head from the last
        if (i >= lists.size()) {
            return nullptr;
        }
        ListNode* mergeHead = helper(i + 1, lists);
        ListNode* newHead = mergeList(mergeHead, lists[i]);
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) { return helper(0, lists); }
};