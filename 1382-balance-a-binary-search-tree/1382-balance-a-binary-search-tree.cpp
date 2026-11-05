/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* solve(vector<int>& v, int left, int right) {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(v[mid]);

        root->left = solve(v, left, mid - 1);
        root->right = solve(v, mid + 1, right);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;

        inorder(root, v);
        return solve(v, 0, v.size() - 1);
    }
};