/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Stack {
    int top;
    struct Node** array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return stack;
}

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;
    struct Stack* s1 = createStack(n);
    struct Stack* s2 = createStack(n);
    push(s1, root);
    int leftToRight = 1;
    while (!isEmpty(s1)) {
        while (!isEmpty(s1)) {
            struct Node* temp = pop(s1);
            printf("%d ", temp->data);
            if (leftToRight) {
                if (temp->left) push(s2, temp->left);
                if (temp->right) push(s2, temp->right);
            } else {
                if (temp->right) push(s2, temp->right);
                if (temp->left) push(s2, temp->left);
            }
        }
        leftToRight = !leftToRight;
        struct Stack* tempStack = s1;
        s1 = s2;
        s2 = tempStack;
    }
    free(s1->array); free(s1);
    free(s2->array); free(s2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root, n);
    free(arr);
    return 0;
}
