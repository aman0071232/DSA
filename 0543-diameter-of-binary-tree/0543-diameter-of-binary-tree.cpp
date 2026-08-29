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
 int calc(TreeNode*root,int &diameter){
    if(root==NULL)return 0;
       int lh=calc(root->left,diameter);
       int rh=calc(root->right,diameter);
       diameter=max(diameter,lh+rh);
       return max(lh,rh)+1;
 }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        calc(root,diameter);
        return diameter;
    }
};