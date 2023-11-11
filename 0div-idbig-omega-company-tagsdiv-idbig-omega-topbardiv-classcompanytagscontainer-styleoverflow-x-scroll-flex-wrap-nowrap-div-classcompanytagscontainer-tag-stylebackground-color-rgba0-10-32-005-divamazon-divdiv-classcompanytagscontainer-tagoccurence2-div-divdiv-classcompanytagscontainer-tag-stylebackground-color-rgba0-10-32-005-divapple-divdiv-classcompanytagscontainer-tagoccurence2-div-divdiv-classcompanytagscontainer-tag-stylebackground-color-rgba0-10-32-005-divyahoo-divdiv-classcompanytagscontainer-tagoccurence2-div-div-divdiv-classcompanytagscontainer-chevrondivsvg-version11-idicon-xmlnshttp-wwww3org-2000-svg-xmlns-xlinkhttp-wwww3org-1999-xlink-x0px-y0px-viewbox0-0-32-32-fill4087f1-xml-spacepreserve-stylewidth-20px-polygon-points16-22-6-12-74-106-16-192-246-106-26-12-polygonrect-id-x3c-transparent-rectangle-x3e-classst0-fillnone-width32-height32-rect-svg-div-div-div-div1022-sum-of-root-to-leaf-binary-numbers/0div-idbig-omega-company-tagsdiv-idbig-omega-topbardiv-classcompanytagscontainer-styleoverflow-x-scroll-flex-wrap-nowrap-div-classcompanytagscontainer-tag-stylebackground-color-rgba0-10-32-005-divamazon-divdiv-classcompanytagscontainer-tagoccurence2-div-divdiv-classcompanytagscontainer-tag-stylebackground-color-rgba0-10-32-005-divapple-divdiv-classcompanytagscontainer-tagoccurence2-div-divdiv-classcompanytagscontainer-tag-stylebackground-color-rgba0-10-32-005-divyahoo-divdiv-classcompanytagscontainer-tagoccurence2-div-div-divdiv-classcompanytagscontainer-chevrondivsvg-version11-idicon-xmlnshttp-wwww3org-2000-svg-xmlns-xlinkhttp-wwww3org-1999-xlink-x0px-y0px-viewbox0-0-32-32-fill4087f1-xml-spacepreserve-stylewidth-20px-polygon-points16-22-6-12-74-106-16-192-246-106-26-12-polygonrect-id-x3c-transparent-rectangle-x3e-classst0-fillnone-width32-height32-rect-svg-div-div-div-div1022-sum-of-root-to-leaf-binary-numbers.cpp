
class Solution {
public:

void dfs(TreeNode* root, int currentNumber, int& sum) {
        if (root == nullptr) {
            return;
        }

        currentNumber = currentNumber * 2 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum += currentNumber;
            return;
        }

        dfs(root->left, currentNumber, sum);
        dfs(root->right, currentNumber, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};