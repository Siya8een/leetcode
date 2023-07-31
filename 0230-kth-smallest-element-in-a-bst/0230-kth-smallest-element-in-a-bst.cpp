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
#include <vector>

class Solution {
public:
    std::vector<int> ans;

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        ans.clear();
        inorderTraversal(root);
        return ans[k - 1];
    }
};
