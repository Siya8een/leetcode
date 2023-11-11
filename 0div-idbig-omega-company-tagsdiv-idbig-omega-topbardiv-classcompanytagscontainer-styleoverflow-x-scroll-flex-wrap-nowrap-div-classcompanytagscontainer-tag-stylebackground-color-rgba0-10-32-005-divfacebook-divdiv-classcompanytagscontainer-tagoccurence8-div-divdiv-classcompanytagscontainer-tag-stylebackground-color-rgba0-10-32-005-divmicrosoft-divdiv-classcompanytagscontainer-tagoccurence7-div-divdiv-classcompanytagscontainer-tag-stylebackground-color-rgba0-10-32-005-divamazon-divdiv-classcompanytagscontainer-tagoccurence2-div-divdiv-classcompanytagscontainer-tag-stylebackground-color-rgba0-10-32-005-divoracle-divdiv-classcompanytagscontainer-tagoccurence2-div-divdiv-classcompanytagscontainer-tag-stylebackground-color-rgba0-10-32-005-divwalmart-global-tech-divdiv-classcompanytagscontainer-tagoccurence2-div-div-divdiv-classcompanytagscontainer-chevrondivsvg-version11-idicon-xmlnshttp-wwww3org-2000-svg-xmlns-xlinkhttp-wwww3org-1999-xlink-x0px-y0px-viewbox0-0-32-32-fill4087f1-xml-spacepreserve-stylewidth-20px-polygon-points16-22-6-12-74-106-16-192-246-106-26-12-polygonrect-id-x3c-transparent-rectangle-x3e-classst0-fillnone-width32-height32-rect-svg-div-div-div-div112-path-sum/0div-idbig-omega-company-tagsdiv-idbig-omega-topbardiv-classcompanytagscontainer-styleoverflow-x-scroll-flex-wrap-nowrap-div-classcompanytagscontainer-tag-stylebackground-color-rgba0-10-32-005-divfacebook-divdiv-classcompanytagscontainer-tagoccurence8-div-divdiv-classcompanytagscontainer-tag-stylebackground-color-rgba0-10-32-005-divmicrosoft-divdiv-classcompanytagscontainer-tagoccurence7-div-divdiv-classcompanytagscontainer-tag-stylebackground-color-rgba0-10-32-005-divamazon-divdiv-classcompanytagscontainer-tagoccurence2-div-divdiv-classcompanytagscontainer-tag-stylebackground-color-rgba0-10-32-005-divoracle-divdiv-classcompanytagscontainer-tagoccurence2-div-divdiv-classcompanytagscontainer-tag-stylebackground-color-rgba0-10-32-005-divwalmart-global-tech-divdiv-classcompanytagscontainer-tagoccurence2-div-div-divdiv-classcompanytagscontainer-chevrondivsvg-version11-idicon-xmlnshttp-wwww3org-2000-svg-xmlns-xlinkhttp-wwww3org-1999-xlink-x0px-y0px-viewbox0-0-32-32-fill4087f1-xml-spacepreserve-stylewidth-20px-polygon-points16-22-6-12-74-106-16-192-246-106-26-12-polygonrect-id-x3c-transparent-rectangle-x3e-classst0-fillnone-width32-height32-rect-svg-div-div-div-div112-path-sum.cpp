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
    
    bool answer( TreeNode* root, int targetSum,int pathsum ){
        // if ( root->val == NULL && targetSum== NULL){
        //     return true;
        // }
        if ( root == NULL ){
            return false;
        }
        int prev= pathsum;
        pathsum = pathsum + root-> val;
        if( root->left==NULL &&root->right==NULL){
        if ( pathsum == targetSum){
            return true;
        }
            
        }
       bool A1 =  answer(root->left,targetSum,pathsum);
       bool A2 =  answer(root->right,targetSum,pathsum);
          pathsum= prev; 
        return A1 || A2;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int pathsum =0; 
       return answer(root,targetSum,pathsum);
        
    }
};