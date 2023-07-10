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
   int solve ( TreeNode* root ){
        if ( root == NULL){
            return 0;
        }
        int left = solve ( root-> left);
        int right = solve ( root -> right );
        if ( left ==0){
            return right +1;
        }
       if ( right ==0){
            return left +1;
        }
       else{
           int height =  min( left,right );
        return height +1;
       }
               
    }
    
    int minDepth(TreeNode* root) {
        
          return solve ( root );
    }
};