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
    int sum = 0;
    
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        inorderTraversal(root->right); // Traverse right subtree first
        
        sum += root->val; // Update the sum
        
        root->val = sum; // Update the node's value with the sum
        
        inorderTraversal(root->left); // Traverse left subtree
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inorderTraversal(root);
        return root;
    }
};
