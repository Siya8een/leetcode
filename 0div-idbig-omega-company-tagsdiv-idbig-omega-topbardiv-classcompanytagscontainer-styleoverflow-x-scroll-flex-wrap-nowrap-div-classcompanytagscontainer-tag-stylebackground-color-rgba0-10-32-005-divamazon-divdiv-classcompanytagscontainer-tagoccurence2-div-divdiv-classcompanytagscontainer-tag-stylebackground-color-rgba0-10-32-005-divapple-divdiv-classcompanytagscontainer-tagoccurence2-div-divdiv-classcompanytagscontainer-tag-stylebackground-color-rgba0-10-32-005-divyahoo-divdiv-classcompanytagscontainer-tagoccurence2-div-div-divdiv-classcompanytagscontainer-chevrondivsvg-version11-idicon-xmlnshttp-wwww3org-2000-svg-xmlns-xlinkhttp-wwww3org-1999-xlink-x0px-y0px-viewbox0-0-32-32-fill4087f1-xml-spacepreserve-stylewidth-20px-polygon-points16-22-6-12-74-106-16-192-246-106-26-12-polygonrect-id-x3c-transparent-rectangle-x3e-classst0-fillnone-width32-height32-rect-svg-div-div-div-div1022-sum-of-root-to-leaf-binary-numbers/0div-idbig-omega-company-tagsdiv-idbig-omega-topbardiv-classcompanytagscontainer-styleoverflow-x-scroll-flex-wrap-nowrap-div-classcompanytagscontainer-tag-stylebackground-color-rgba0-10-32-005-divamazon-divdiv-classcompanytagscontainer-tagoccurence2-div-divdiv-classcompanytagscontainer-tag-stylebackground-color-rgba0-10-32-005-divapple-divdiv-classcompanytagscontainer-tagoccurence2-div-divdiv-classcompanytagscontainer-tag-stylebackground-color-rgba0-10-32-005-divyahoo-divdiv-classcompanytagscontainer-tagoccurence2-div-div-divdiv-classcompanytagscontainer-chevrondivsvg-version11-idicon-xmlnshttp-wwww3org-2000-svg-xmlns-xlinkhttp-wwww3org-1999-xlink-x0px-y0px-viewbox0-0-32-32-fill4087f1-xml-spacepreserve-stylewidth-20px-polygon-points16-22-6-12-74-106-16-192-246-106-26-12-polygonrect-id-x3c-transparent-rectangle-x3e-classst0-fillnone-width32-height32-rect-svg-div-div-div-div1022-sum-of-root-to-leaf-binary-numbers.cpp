
class Solution {
public:

void dfs(TreeNode* root, int &currentNumber, int& sum) {
        if (root == nullptr) {
            return;
        }
    int prev= currentNumber;
        currentNumber = currentNumber * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += currentNumber;
          
        }
        dfs(root->left, currentNumber, sum);
        dfs(root->right, currentNumber, sum);
     currentNumber=prev;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int currentNumber = 0;
        dfs(root, currentNumber, sum);
        return sum;
    }
};