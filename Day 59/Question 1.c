/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int inorder[100], postorder[100];
int postIndex, n;

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* build(int start, int end) {
    if (start > end)
        return NULL;

    int val = postorder[postIndex--];
    struct Node* root = createNode(val);

    if (start == end)
        return root;

    int inIndex = search(start, end, val);

    root->right = build(inIndex + 1, end);
    root->left = build(start, inIndex - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = build(0, n - 1);

    preorder(root);

    return 0;
}
