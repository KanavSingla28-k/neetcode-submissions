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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxD = 0;

        solve(root, maxD);

        return maxD;
    }

    void solve(TreeNode* node, int& maxD){
        int lefth = height(node->left);
        int righth = height(node->right);
        maxD = max(maxD, max(lefth, righth)+1);
    }

    int height(TreeNode* node){
        if (!node) return 0;
        if (!node->left && !node->right) return 1;

        return max(height(node->left), height(node->right))+1;
    }
};
