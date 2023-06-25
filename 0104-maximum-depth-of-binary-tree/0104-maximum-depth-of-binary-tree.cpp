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
     int solve(TreeNode* root, int count, int h) {
        if (root == nullptr) {
            return h; // Return the height as 0 if the node is null
        }

        if (root->left == nullptr && root->right == nullptr) {
            return count; // Return the count if the current node is a leaf node
        }

        int h1 = solve(root->left, count + 1, h);
        int h2 = solve(root->right, count + 1, h);
        return std::max(h1, h2);
    }

    int maxDepth(TreeNode* root) {
        int count = 0;
        if (root == nullptr) {
            return 0; // Return the height as 0 if the node is null
        }
        int h = 0;
        int ans = solve(root, count, h)+1;
        return ans;
    }

};