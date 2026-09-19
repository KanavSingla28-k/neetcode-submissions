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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int l, int r){
        if (l>r) return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);

        int idx2 = search(inorder, l, r, preorder[idx]);
        idx++;

        node->left = build(preorder, inorder, idx, l, idx2-1);
        node->right = build(preorder, inorder, idx, idx2+1, r);

        return node;
    }

    int search(vector<int>& inorder, int l, int r, int t){
        for (int i = l; i<=r; i++){
            if (inorder[i] == t) return i;
        }
        return -1;
    }
};
