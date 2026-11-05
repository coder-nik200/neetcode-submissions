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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1) temp->next = list1;
        if (list2) temp->next = list2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0) return nullptr;

        while (n > 1) {
            int index = 0;

            for (int i = 0; i < n; i += 2) {
                if (i + 1 < n) {
                    lists[index++] = merge(lists[i], lists[i + 1]);
                }
                else {
                    lists[index++] = lists[i];
                }
            }

            n = index;
        }

        return lists[0];
    }
};
