void inorderTraversalHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    // Traverse left subtree
    inorderTraversalHelper(root->left, result, index);

    // Visit the current node
    result[*index] = root->val;
    (*index)++;

    // Traverse right subtree
    inorderTraversalHelper(root->right, result, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));  // Assume max 100 nodes in the tree
    *returnSize = 0;
    inorderTraversalHelper(root, result, returnSize);
    return result;
}
