#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root, long long min_val, long long max_val) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val > min_val && root->val < max_val) {
            bool left = isValidBST(root->left, min_val, root->val);
            bool right = isValidBST(root->right, root->val, max_val);
            return left && right;
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long min_val = std::numeric_limits<long long>::min();
        long long max_val = std::numeric_limits<long long>::max();
        return isValidBST(root, min_val, max_val);
    }
};
