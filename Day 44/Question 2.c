/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL) return result;

    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];

        result[(*returnSize)++] = node->val;

        if (node->right != NULL)
            stack[++top] = node->right;

        if (node->left != NULL)
            stack[++top] = node->left;
    }

    return result;
}
