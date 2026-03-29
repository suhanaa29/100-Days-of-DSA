/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree*/

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            struct TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
