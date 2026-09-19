class Solution {
public:
    int ans = 0;

    int kthSmallest(TreeNode* root, int k) {
        int size = 0;
        inorder(root, size, k);
        return ans;
    }

    void inorder(TreeNode* node, int& size, int k) {
        if (!node) return;

        inorder(node->left, size, k);

        size++;

        if (size == k) {
            ans = node->val;
            return;
        }

        inorder(node->right, size, k);
    }
};