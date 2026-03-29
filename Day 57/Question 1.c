/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.*/

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

void mirror(struct Node* root) {
    if (!root) return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void printInorder(struct Node* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** q = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
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

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    mirror(root);
    printInorder(root);
    printf("\n");

    free(arr);
    return 0;
}
