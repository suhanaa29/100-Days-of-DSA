/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between)*/

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** res = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[2000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    bool reverse = false;

    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[*returnSize] = levelSize;
        res[*returnSize] = malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            
            int index = reverse ? (levelSize - 1 - i) : i;
            res[*returnSize][index] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        reverse = !reverse;
        (*returnSize)++;
    }

    return res;
}
