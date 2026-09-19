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
    void indeg(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;
        indeg(root->left, arr);
        arr.push_back(root->val);
        indeg(root->right, arr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        vector<int> arr;
        indeg(root, arr);
        sort(arr.begin(), arr.end());
        int maxi = 0;
        for (int i = 0; i < arr.size();) {
            int j = i;
            while (j < arr.size() && arr[j] == arr[i])
                j++;
            int count = j - i;
            maxi = max(maxi, count);
            i = j;
        }
        for (int i = 0; i < arr.size();) {
            int j = i;
            while (j < arr.size() && arr[j] == arr[i])
                j++;
            int count = j - i;
            if (count == maxi)
                ans.push_back(arr[i]);
            i = j;
        }
        return ans;
    }
};