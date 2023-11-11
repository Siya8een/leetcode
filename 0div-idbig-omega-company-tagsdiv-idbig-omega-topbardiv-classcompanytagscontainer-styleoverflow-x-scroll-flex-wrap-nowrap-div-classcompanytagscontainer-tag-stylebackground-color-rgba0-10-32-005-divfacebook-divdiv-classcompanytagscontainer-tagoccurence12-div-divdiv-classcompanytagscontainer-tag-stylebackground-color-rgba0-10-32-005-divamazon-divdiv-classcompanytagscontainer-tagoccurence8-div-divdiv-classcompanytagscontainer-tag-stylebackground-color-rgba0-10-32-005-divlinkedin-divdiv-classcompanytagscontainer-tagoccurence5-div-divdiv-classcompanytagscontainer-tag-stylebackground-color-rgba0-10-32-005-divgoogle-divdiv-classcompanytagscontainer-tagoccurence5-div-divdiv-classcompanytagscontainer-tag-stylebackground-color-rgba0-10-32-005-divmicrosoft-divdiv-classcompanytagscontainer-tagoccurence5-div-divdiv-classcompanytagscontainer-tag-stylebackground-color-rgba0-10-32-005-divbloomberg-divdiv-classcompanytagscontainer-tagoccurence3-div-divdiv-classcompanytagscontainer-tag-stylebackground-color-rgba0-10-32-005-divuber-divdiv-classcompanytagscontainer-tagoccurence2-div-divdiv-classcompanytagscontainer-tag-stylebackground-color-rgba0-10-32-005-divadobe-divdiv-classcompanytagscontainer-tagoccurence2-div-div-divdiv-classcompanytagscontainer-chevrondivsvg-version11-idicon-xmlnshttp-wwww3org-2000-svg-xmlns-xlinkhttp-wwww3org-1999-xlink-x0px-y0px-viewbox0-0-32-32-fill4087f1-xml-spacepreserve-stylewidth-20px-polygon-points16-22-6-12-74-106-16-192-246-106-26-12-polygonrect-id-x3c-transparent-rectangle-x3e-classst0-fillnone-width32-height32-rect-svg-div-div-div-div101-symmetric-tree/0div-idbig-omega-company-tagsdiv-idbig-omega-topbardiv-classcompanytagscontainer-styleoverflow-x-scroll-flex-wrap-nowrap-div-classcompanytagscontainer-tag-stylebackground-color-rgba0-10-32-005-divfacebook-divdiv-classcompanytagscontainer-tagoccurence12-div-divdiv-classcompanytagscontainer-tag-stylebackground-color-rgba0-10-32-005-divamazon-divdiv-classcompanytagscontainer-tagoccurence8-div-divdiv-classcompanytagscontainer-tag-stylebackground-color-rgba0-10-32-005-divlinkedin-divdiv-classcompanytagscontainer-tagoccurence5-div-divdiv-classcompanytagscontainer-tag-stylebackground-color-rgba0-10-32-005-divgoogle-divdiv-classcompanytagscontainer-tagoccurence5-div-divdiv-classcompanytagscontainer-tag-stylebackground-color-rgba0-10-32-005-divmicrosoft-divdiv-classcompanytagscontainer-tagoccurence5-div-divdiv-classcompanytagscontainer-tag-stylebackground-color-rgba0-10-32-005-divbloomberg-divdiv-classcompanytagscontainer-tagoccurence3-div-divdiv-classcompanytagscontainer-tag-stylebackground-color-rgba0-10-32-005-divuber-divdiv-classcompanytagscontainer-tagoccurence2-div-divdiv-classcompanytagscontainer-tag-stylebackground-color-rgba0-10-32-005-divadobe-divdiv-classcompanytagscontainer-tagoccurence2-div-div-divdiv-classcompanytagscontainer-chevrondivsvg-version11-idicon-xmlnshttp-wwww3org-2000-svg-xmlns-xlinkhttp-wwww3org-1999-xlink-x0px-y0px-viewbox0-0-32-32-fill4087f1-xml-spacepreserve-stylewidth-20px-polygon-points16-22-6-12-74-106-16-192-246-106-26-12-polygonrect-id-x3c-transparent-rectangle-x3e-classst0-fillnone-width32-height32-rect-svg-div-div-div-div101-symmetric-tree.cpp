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
    bool ispal(vector<int>& level){
        for ( int i =0; i < level.size()/2 ;i++){
            if ( level[i]!= level[level.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        while( !q.empty()){
              int s = q.size();
            
             vector<int> level;
            
            for( int i =0 ; i < s;i++){
                TreeNode* node = q.front();
                q.pop();
                if ( node->left != NULL)
                {
                    q.push(node->left);
                    level.push_back(node->left->val);
                }
                else{
                     level.push_back(1e9);
                }
                if ( node->right != NULL){
                    q.push(node->right);
                    level.push_back(node->right->val);
                     
                }
                else{
                     level.push_back(1e9  );
                }
            }  
          if(!ispal(level)){
              return false;
          }
        }
        return true;
    }
};