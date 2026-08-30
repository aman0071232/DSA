/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
vector<int>ans;
void finddown(TreeNode*root,int  k){
        if (root == NULL || k < 0)
            return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        finddown(root->left, k - 1);
        finddown(root->right, k - 1);

}
int findTarget(TreeNode* root,TreeNode*target,int k){
        if (root == NULL)
            return -1;

        if (root == target) {
            finddown(root, k);
            return 1;
        }
        int leftdist = findTarget(root->left, target, k);
        if (leftdist != -1) {
            if (leftdist == k)
                ans.push_back(root->val);
            else
                finddown(root->right, k - leftdist - 1);
            return leftdist + 1;
        }
        int rightdist = findTarget(root->right, target, k);
        if (rightdist != -1) {
            if (rightdist == k)
                ans.push_back(root->val);
            else
                finddown(root->left, k - rightdist - 1);
            return rightdist + 1;
        }
        return -1;
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findTarget(root, target, k);
        return ans;
    }
};