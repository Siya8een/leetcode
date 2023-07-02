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
// class Solution {
// public:
//     void sum(TreeNode* root) {
//         int sum =0;
//         if ( root == NULL){
//             return ;
//         }
//          sum( root->right);
//         sum = sum + root -> val;
//          root -> val = sum;
//         sum ( root-> left);

//     }
//     TreeNode* bstToGst(TreeNode* root) {
//         sum( root);
//         return root ;
//     }
// };
class Solution {
public:
    int summ = 0;
    void sum(TreeNode* root) {
        
        if (root == NULL) {
            return;
        }
        sum(root->right);
        summ = summ + root->val;
        root->val = summ;
        sum(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        sum(root);
        return root;
    }
};

