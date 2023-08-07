class Solution {
public:
    int dia(TreeNode* root, int& max_diameter) {
        if (root == NULL) {
            return 0;
        }
        int left_height = dia(root->left, max_diameter);
        int right_height = dia(root->right, max_diameter);
      
        int diameter_through_root = left_height + right_height;
        max_diameter = max(max_diameter, diameter_through_root);
        
        return 1 + max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int max_diameter = 0;
        dia(root, max_diameter);
        return max_diameter;
    }
};
