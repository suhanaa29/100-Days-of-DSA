/*Remove loop in Linked List*/

class Solution {
public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
            return;

        slow = head;

        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = nullptr;
    }
};
