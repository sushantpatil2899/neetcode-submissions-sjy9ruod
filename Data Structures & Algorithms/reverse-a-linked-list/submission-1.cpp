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

class Solution {
public:

    ListNode* recursiveReverseList(ListNode* curr, ListNode* prev) {
        if (curr->next == nullptr) {
            curr->next = prev;
            return curr;
        }
        ListNode* x = recursiveReverseList(curr->next, curr);
        curr->next = prev;
        return x;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        return recursiveReverseList(head, nullptr);
    }
};
