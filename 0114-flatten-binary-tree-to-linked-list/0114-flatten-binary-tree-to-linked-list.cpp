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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        // Store the original right child in a temporary variable
        TreeNode* temp=root->right;
        
        // Make the left subtree the new right subtree
        root->right=root->left;
        root->left=NULL;

        // Find the rightmost node of the newly attached left subtree
        TreeNode* rightMost=root;
        while(rightMost->right)
        {
            rightMost=rightMost->right;
        }

        // Attach the original right subtree to the rightmost node of the new right subtree
        rightMost->right=temp;

        // Update the root to the current right child and continue the recursive call
        root=root->right;
        flatten(root);

    }
};