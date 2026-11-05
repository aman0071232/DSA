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
    int ans = 0;
    vector<int> solve(TreeNode* root) {
        if (root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        vector<int> curr(4);

        if (left[0] && right[0] && root->val > left[2] &&
            root->val < right[1]) {
            curr[0] = 1;
            curr[1] = min(root->val, left[1]);
            curr[2] = max(root->val, right[2]);
            curr[3] = root->val + left[3] + right[3];

            ans = max(curr[3], ans);
        } else {
            curr[0] = 0;
            curr[1] = INT_MIN;
            curr[2] = INT_MAX;
            curr[3] = 0;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};