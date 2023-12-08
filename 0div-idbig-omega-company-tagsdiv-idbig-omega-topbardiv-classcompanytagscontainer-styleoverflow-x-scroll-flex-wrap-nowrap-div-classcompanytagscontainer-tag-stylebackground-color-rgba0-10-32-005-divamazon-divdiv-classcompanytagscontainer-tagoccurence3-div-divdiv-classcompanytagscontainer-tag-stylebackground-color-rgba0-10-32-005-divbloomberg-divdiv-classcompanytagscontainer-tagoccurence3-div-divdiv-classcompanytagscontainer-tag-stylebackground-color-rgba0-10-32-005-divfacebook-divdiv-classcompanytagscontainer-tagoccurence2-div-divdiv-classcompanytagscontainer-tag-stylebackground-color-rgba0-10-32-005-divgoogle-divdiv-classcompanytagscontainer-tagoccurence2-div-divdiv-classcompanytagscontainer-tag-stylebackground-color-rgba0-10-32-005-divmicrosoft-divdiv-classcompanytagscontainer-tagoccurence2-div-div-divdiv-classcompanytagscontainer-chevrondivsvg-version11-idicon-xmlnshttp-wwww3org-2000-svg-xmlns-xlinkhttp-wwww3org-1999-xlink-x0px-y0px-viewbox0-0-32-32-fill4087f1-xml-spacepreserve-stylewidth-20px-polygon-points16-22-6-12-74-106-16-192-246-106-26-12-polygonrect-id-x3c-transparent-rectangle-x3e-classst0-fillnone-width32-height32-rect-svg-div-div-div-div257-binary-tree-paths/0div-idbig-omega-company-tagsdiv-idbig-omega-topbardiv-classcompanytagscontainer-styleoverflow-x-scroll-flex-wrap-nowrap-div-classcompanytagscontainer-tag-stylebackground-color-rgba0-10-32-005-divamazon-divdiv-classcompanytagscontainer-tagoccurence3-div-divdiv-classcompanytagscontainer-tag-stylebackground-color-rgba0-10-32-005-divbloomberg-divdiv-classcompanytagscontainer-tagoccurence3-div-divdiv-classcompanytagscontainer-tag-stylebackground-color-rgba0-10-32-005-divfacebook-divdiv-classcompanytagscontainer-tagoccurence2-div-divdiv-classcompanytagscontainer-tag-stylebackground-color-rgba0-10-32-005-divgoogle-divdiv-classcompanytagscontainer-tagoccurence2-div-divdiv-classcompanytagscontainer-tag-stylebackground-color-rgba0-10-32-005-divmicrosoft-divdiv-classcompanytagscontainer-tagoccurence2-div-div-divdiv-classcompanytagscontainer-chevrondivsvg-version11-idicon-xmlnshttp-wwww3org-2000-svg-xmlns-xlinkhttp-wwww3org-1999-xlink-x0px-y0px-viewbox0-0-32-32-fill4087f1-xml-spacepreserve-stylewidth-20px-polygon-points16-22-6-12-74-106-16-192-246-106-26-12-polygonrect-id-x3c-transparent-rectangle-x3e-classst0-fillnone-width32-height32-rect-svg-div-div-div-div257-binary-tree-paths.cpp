#include <vector>
#include <string>


class Solution {
public:
    void path(TreeNode* root, vector<string>& output, string ans) {
        if (root == NULL) {
            return;
        }

        // Append the current node value to the current path
        ans += to_string(root->val);

        // If it's a leaf node, add the path to the output vector
        if (root->left == NULL && root->right == NULL) {
            output.push_back(ans);
            return;
        }

        // If not a leaf node, continue traversal to the left and right
        if (root->left != NULL) {
            path(root->left, output, ans + "->");
        }

        if (root->right != NULL) {
            path(root->right, output, ans + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        if (root == NULL) {
            return output;
        }
        path(root, output, "");
        return output;
    }
};
