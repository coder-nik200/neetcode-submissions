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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val == val) {
                int duplicate = temp->val;

                while (temp != nullptr && temp->val == duplicate) {
                    temp = temp->next;
                }

                prev->next = temp;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};