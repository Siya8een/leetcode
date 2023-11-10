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
     void numbervector(TreeNode* root, vector<int>& paths, int number) {
        if (root == nullptr) {
            return;
        }

       
        number = number * 10 + root->val;

        
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(number);
        }

        // Recursively traverse the left and right subtrees
        numbervector(root->left, paths, number);
        numbervector(root->right, paths, number);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> paths;
        int number = 0;
        
        // get all the numbers in ans ;
        numbervector(root, paths, number);

        // Now you can do something with the paths vector, e.g., calculate the sum
        int totalSum = 0;
        for (int num : paths) {
            totalSum += num;
        }

        return totalSum;
    }


};