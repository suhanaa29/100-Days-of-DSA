/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree*/

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int map[6001];

struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    int inIndex = map[rootVal + 3000];
    int leftSize = inIndex - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1);
}
