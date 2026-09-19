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
          if(root==NULL){
            return;
        }
        indeg(root->left,arr);
        arr.push_back(root->val);
        indeg(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        indeg(root, arr);
        return arr[k - 1];
    }
};