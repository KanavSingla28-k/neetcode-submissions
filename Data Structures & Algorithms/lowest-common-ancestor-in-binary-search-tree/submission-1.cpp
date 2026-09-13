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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        int a = root->val;
        int pv = p->val;
        int qv = q->val;

        if ((pv<=a && qv>=a) || (pv>=a && qv<=a)) return root;

        if (pv<=a && qv<=a) return lowestCommonAncestor(root->left, p, q);
        if (pv>=a && qv>=a) return lowestCommonAncestor(root->right, p, q);

        return nullptr;
    }
};
