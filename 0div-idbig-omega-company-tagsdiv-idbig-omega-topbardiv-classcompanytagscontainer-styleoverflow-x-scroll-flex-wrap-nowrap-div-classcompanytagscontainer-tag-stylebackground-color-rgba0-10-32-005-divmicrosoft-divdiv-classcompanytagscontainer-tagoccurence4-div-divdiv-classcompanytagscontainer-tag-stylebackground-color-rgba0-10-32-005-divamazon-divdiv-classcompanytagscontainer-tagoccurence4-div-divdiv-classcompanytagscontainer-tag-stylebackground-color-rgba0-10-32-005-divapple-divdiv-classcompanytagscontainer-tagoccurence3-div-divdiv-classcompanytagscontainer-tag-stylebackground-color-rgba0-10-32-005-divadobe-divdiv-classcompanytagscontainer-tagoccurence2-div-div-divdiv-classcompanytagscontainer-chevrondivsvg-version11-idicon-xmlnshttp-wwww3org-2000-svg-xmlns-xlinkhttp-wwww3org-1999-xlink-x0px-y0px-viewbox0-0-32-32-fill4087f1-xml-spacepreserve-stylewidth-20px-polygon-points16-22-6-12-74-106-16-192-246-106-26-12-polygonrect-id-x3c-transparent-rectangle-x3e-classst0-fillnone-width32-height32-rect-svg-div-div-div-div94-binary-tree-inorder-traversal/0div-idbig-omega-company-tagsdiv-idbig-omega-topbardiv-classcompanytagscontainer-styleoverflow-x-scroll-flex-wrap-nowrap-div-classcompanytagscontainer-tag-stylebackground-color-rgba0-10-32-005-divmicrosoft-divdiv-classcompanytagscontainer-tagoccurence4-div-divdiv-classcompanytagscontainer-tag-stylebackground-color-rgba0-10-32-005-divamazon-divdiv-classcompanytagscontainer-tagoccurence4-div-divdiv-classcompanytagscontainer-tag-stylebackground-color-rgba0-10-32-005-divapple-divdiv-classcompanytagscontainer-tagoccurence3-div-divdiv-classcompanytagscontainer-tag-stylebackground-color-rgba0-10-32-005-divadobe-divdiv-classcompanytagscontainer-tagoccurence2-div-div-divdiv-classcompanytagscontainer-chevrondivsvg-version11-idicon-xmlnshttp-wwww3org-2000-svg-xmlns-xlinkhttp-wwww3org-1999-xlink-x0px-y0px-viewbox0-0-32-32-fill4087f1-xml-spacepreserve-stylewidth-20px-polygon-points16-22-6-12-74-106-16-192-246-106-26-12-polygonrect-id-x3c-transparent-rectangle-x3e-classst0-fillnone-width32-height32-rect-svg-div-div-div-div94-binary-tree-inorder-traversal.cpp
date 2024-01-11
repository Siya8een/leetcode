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
    vector<int> inorderTraversal(TreeNode* root) {
        stack < TreeNode* > st ;
        TreeNode* x = root;
         
        vector < int > inorder;
        while (true){
            if ( x != NULL){
                st.push( x );
                x = x -> left;
                
            }
            else {
                if ( st.empty()){
                    break;
                }
                x = st.top();
                st.pop();
                inorder.push_back(x-> val);
                x = x -> right;
            }
        }
        return inorder;
    }
};