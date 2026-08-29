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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        // Initialize maximum width as 0
        long long maxWidth = 0;

        // Queue to perform level-order traversal
        // Each element is a pair of node and its index
        queue<pair<TreeNode*, long long>> q;

        // Push root node with index 0
        q.push({root, 0});

        // Continue BFS until queue becomes empty
        while (!q.empty()) {

            // Get the number of nodes at current level
            long long size = q.size();

            // Store the index of the first node at this level
            long long minIndex = q.front().second;

            // Initialize variables to track first and last index
            long long first = 0;
            long long last = 0;

            // Traverse all nodes at the current level
            for (int i = 0; i < size; i++) {

                // Get the current node and its relative index
                long long currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;

                // Pop the current node from the queue
                q.pop();

                // Update the first index if it's the first node
                if (i == 0)
                    first = currIndex;

                // Update the last index if it's the last node
                if (i == size - 1)
                    last = currIndex;

                // If left child exists, push it with calculated index
                if (node->left)
                    q.push({node->left, 2 * currIndex + 1});

                // If right child exists, push it with calculated index
                if (node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            // Update the maximum width if needed
            maxWidth = max(maxWidth, last - first + 1);
        }

        // Return the result
        return maxWidth;
    
    }
};