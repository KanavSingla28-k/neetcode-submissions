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
int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        height(root);

        return ans;
    }

    int height(TreeNode* node){
        if (!node) return 0;

        int l = height(node->left);
        int r = height(node->right);

        ans = max(ans, l+r);
        return max(l, r)+1;
    }
};
