/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        bool  t = true;
        solve(root, t);
        return t;
    }

    void solve(TreeNode* node, bool& t){
        if (!node) return;
        int l = height(node->left);
        int r = height(node->right);

        if (abs(l-r) > 1){
            t = false;
            return;
        }

        solve(node->left, t);
        solve(node->right, t);
    }

    int height(TreeNode* node){
        if (!node) return 0;
        return 1+max(height(node->left), height(node->right));
    }
};
