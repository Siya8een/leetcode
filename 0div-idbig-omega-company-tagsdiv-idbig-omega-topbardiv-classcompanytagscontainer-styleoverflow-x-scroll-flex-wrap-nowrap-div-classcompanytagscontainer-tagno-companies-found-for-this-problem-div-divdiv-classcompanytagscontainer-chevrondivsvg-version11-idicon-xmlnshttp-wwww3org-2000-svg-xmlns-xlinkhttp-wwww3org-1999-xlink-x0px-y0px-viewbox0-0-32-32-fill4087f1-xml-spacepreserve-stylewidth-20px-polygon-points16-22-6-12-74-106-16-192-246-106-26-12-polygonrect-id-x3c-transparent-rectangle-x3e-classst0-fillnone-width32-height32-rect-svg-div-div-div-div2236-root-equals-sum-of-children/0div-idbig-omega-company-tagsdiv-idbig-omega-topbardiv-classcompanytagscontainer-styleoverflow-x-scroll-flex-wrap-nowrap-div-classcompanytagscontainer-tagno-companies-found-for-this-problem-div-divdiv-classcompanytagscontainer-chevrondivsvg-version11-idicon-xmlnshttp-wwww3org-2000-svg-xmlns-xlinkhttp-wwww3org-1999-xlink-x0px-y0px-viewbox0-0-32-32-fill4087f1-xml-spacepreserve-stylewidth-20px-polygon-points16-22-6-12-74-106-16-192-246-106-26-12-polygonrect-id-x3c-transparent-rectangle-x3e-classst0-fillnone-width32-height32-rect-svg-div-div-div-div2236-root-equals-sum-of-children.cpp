
class Solution {
public:
    bool check(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        int sum = 0;
        if (root->left != nullptr) {
            sum += root->left->val;
        }
        if (root->right != nullptr) {
            sum += root->right->val;
        }

        return (root->val == sum) && check(root->left) && check(root->right);
    }

    bool checkTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return check(root);
    }
};
