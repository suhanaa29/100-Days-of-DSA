/*Given the head of a singly linked list, reverse the list, and return the reversed list*/

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}
