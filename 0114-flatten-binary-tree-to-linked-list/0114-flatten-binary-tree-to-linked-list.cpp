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
        if ( root == NULL){
             return;
        }
         TreeNode* temp=root->right;
        
        // left = new right subtree
        root->right=root->left;
        root->left=NULL;
        TreeNode* rightmost = root ;
        while ( rightmost -> right != NULL){
            rightmost = rightmost -> right;
        }
        rightmost->right=temp;
root=root->right;
        flatten(root);
    }
};