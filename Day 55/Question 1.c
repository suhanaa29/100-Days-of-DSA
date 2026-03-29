/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** q = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[tail++] = curr->right;
        }
    }
    free(q);
    return root;
}

void rightView(struct Node* root, int n) {
    if (!root) return;
    struct Node** q = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    q[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = q[head++];
            
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) q[tail++] = curr->left;
            if (curr->right) q[tail++] = curr->right;
        }
    }
    free(q);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = buildTree(arr, n);
    rightView(root, n);
    
    free(arr);
    return 0;
}
