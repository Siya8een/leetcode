class Solution {
public:
    int solve(TreeNode* root, int& maxsum) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, maxsum);
        int right = solve(root->right, maxsum);

        int current_max_sum = max(root->val, max(left, right) + root->val);
        
        int current_sum = root->val + left + right;
      
        maxsum = max(maxsum, max(current_max_sum, current_sum));
        
        return current_max_sum;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};
