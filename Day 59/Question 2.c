/*Given two integer arrays inorder and postorder where inorder
is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree*/

#include <stdlib.h>

int map[6001];
int postIndex;

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder) {

    if (inStart > inEnd)
        return NULL;

    int val = postorder[postIndex--];
    struct TreeNode* root = createNode(val);

    int inIndex = map[val + 3000];

    root->right = build(inorder, inIndex + 1, inEnd, postorder);
    root->left = build(inorder, inStart, inIndex - 1, postorder);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    postIndex = postorderSize - 1;

    return build(inorder, 0, inorderSize - 1, postorder);
}
