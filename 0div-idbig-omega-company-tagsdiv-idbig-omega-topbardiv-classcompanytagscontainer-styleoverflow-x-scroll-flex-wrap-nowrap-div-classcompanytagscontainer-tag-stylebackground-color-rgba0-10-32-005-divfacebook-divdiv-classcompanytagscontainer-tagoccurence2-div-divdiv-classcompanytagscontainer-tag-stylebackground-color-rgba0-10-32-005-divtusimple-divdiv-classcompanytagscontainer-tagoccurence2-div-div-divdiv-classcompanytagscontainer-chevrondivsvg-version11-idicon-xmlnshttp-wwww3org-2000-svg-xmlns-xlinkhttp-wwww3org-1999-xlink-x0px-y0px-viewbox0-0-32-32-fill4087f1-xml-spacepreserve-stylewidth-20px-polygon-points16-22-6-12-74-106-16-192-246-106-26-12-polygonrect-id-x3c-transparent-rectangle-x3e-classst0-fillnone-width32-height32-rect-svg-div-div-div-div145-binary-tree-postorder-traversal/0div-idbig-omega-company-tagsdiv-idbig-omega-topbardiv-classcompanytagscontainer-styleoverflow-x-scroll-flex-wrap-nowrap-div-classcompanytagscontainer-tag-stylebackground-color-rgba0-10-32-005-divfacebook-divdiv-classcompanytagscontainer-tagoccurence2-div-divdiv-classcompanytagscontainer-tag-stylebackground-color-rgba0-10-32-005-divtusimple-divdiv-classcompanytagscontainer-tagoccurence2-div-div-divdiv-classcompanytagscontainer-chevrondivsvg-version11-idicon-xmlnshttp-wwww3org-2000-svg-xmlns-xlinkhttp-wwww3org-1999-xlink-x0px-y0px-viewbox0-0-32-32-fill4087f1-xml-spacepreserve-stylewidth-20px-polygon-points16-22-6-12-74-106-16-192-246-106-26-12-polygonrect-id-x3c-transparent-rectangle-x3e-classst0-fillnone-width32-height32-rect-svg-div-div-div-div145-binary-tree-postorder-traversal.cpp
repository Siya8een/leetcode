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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
       stack < TreeNode* > st1;
        stack < int > st2;
        st1.push( root );
        
        while ( !st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node->val);
            if ( node -> left != NULL){
                
                st1.push( node-> left); 
            }
            if ( node -> right != NULL){
              
                st1.push( node-> right); 
            }
            
            
            
        }
        vector < int > ans;
        while ( !st2.empty()){
            int a = st2.top();
            st2.pop();
            ans. push_back(a);
        }
        return ans;
    }
};