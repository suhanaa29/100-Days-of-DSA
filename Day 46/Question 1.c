/*Problem: Level Order Traversal*/

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        result[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}
