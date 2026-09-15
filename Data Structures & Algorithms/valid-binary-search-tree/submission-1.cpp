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
    bool isValidBST(TreeNode* root) {
        
        return solve(root, INT_MIN, INT_MAX);
    }

    bool solve(TreeNode* node, int mini, int maxi){
        if (!node) return true;

        if (node->val <= mini || node->val >= maxi) return false;

        return solve(node->left, mini, node->val) && solve(node->right, node->val, maxi);
    }
};
