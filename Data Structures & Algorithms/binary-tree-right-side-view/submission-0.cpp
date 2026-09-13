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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;

        while (!q.empty()){
            int size = q.size();
            TreeNode* rightmost = nullptr;

            for (int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                rightmost = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (rightmost) res.push_back(rightmost->val);
        }
        return res;
    }
};
