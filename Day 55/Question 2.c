/*Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom*/

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    int* res = malloc(100 * sizeof(int));
    struct TreeNode* queue[100];
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[head++];
            
            if (i == levelSize - 1) {
                res[(*returnSize)++] = curr->val;
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    return res;
}
