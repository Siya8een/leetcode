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