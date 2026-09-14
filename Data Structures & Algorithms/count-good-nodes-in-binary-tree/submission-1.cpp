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
    int goodNodes(TreeNode* root) {

        vector<int> path;
        solve(root, path);

        return ans;
    }

    void solve(TreeNode* node, vector<int>& path){
        if (!node) return;

        if (compare(node->val, path)) ans++;
        path.push_back(node->val);
        solve(node->left, path);
        solve(node->right, path);

        path.pop_back();
    }

    bool compare(int x, vector<int>& path){
        bool ans = true;
        for (int num: path){
            if (num>x) ans = false;
        }
        return ans;
    }
};
