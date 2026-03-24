/*Given the root of a binary tree, return the sum of all left leaves*/

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;

    int sum = 0;

    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
