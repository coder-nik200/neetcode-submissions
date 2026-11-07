/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        /*
        1. Insert copyNodes in between
        2. connect random pointers
        3. connect next pointers
        */

        Node* temp = head;
        Node* copyNode = nullptr;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        // Insert copyNodes in between
        while (temp != nullptr) {
            copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        // connect random pointers
        temp = head;
        while (temp != nullptr) {
            copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }

        // connect next pointers
        temp = head;
        while (temp != nullptr) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
