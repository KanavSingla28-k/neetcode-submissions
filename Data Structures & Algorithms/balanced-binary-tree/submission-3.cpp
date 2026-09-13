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
    bool t = true;
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        solve(root);
        return t;
    }

    int solve(TreeNode* node){
        if (!node) return 0;
        int l = solve(node->left);
        int r = solve(node->right);

        if (abs(l-r) > 1){
            t = false;
        }

        return 1+max(l, r);
    }
};
