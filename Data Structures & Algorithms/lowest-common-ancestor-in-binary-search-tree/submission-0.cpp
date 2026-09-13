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
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> fp;
        vector<TreeNode*> fq;

        path(root, p, fp);
        path(root, q, fq);

        findans(fp, fq);

        return ans;
    }

    void path(TreeNode* root, TreeNode* p, vector<TreeNode*>& q){
        if (!root) return;

        if (root->val == p->val){
            q.push_back(root);
            return;
        }

        q.push_back(root);
        if (root->val > p->val) path(root->left, p, q);
        else path(root->right, p, q);
    }

    void findans(vector<TreeNode*>& fp, vector<TreeNode*>& fq){
        int n = fp.size();
        int m = fq.size();

        for (int i = n-1; i>=0; i--){
            for (int j = m-1; j>=0; j--){
                if (fp[i]->val == fq[j]->val) {
                    ans = fp[i];
                    return;
                }
            }
        }
    }
};
