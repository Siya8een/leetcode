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
    void dfs( TreeNode* root, int targetSum, int sum , vector <vector<int>>&ans,vector<int> path){
        if ( root == NULL){
             return;
        }
        int prev = sum;
        path.push_back(root->val);
        sum = sum + root-> val;
        if ( root -> left == NULL && root->right == NULL){
            if ( sum ==  targetSum){
                ans.push_back(path);
            }
        }
        
        dfs( root->left , targetSum, sum, ans , path);
        dfs( root->right , targetSum, sum, ans , path);
        
        sum = prev;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum =0; 
        vector <vector <int >> ans;
        vector<int> path;
        dfs( root, targetSum, sum, ans , path);
        return ans;
    }
};