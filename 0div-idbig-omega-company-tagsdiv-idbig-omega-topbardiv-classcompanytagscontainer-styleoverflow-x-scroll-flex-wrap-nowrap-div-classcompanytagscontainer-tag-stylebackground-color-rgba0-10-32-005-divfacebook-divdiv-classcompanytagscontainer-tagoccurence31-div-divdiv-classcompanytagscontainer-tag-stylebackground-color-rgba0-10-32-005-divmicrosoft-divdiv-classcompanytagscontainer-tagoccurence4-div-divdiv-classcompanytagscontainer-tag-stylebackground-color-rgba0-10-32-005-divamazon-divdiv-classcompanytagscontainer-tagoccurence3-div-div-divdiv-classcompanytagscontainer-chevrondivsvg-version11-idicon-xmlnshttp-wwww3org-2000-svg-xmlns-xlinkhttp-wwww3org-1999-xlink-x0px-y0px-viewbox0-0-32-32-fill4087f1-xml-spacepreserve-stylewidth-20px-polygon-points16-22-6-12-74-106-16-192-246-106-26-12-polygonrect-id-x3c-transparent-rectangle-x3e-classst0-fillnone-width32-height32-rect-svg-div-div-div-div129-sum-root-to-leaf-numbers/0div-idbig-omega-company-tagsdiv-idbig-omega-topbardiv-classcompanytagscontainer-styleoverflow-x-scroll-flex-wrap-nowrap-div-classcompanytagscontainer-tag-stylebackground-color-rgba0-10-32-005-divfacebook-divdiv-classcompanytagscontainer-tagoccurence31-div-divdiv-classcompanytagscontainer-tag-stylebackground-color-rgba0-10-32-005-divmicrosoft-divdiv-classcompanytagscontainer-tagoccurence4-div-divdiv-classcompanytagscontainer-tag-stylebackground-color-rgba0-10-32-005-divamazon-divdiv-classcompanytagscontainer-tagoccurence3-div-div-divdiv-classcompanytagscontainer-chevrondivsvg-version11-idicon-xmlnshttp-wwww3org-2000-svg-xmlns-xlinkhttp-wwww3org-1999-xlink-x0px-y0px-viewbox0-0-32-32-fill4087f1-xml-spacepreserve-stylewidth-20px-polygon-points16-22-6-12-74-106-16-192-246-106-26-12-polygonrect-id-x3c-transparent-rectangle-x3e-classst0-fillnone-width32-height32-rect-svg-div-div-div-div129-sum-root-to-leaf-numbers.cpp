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
     void numbervector(TreeNode* root,  int number, int& sum) {
        if (root == nullptr) {
            return;
        }
        number = number * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum = sum + number;
        }

        numbervector(root->left, number,sum);
        numbervector(root->right,  number,sum);
    }

    int sumNumbers(TreeNode* root) {
        
        int number = 0;
        int sum =0;
        // get all the numbers in ans ;
        numbervector(root,  number, sum);
        

        return sum;
    }
};