/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *last = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    if (last != NULL)
        last->next = head;

    if (head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}
