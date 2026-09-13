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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }

    bool solve(TreeNode* p, TreeNode* q){
        if (!p || !q) return p == q;

        if (p->val == q->val){
            if (sameTree(p, q)) return true;
        }

        return solve(p->left, q) || solve(p->right, q);
    }

    bool sameTree(TreeNode* p, TreeNode* q){
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;

        return (sameTree(p->left, q->left) && sameTree(p->right, q->right));
    }
};
