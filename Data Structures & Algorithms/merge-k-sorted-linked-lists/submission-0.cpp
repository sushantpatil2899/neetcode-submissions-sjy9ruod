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
    ListNode* mergeLinkedLists(ListNode* left, ListNode* right) {
        ListNode dummy;   // dummy head
        ListNode* curr = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        // Attach the remainder
        if (left) curr->next = left;
        if (right) curr->next = right;

        return dummy.next;
    }

    ListNode* mergeKListsRecursively(vector<ListNode*>& lists, int s, int e) {
        if (s==e) {
            return lists[s];
        }

        int m = s + ((e-s)/2);
        ListNode* head1 = mergeKListsRecursively(lists, s, m);
        ListNode* head2 = mergeKListsRecursively(lists, m+1, e);
        return mergeLinkedLists(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* curr = nullptr;
        if (!lists.size()) {
            return curr;
        }
        return mergeKListsRecursively(lists, 0, lists.size()-1);
    }
};