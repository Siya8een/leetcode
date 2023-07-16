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
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftCount = solve(root->left);
        int rightCount = solve(root->right);
        return leftCount + rightCount + 1;
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};
