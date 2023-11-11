class Solution {
public:
     void numbervector(TreeNode* root, int& number, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
         int prevNumber = number; 
        number = number * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(number);
        }

        numbervector(root->left, number, ans);
        numbervector(root->right, number, ans);
         number=prevNumber;
    }

    int sumNumbers(TreeNode* root) {
        int number = 0;
        vector<int> ans;
        numbervector(root, number, ans);

        int sum = accumulate(ans.begin(), ans.end(), 0);
        return sum;
    }
};
