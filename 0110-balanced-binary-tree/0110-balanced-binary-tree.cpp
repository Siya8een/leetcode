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
    int find(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Height of empty subtree is 0
        }
        
        int heightL = find(root->left); // Height of left subtree
        int heightR = find(root->right); // Height of right subtree
        
        int height = max(heightL, heightR) + 1; // Height of current subtree
        
        return height;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true; // Empty tree is considered balanced
        }
        
        int heightL = find(root->left); // Height of left subtree
        int heightR = find(root->right); // Height of right subtree
        
        int heightDiff = abs(heightL - heightR); // Difference in heights
        
        if (heightDiff > 1) {
            return false; // Heights differ by more than 1, tree is unbalanced
        }
        
        // Check if left and right subtrees are also balanced
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        
        return leftBalanced && rightBalanced;
    }
};
