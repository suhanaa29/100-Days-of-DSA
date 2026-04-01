/*Problem Statement: 
Construct a binary tree from given preorder and inorder traversal arrays*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int preorder[100], inorder[100];
int preIndex = 0, n;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int start, int end) {
    if (start > end)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct Node* root = createNode(rootVal);

    if (start == end)
        return root;

    int inIndex = search(start, end, rootVal);

    root->left = buildTree(start, inIndex - 1);
    root->right = buildTree(inIndex + 1, end);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(0, n - 1);

    postorder(root);

    return 0;
}
