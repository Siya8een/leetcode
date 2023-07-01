class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root, ans);
        
        int i = 0;
        int j = ans.size() - 1;
        
        while (i < j) {
            int sum = ans[i] + ans[j];
            
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        
        return false;
    }
};
