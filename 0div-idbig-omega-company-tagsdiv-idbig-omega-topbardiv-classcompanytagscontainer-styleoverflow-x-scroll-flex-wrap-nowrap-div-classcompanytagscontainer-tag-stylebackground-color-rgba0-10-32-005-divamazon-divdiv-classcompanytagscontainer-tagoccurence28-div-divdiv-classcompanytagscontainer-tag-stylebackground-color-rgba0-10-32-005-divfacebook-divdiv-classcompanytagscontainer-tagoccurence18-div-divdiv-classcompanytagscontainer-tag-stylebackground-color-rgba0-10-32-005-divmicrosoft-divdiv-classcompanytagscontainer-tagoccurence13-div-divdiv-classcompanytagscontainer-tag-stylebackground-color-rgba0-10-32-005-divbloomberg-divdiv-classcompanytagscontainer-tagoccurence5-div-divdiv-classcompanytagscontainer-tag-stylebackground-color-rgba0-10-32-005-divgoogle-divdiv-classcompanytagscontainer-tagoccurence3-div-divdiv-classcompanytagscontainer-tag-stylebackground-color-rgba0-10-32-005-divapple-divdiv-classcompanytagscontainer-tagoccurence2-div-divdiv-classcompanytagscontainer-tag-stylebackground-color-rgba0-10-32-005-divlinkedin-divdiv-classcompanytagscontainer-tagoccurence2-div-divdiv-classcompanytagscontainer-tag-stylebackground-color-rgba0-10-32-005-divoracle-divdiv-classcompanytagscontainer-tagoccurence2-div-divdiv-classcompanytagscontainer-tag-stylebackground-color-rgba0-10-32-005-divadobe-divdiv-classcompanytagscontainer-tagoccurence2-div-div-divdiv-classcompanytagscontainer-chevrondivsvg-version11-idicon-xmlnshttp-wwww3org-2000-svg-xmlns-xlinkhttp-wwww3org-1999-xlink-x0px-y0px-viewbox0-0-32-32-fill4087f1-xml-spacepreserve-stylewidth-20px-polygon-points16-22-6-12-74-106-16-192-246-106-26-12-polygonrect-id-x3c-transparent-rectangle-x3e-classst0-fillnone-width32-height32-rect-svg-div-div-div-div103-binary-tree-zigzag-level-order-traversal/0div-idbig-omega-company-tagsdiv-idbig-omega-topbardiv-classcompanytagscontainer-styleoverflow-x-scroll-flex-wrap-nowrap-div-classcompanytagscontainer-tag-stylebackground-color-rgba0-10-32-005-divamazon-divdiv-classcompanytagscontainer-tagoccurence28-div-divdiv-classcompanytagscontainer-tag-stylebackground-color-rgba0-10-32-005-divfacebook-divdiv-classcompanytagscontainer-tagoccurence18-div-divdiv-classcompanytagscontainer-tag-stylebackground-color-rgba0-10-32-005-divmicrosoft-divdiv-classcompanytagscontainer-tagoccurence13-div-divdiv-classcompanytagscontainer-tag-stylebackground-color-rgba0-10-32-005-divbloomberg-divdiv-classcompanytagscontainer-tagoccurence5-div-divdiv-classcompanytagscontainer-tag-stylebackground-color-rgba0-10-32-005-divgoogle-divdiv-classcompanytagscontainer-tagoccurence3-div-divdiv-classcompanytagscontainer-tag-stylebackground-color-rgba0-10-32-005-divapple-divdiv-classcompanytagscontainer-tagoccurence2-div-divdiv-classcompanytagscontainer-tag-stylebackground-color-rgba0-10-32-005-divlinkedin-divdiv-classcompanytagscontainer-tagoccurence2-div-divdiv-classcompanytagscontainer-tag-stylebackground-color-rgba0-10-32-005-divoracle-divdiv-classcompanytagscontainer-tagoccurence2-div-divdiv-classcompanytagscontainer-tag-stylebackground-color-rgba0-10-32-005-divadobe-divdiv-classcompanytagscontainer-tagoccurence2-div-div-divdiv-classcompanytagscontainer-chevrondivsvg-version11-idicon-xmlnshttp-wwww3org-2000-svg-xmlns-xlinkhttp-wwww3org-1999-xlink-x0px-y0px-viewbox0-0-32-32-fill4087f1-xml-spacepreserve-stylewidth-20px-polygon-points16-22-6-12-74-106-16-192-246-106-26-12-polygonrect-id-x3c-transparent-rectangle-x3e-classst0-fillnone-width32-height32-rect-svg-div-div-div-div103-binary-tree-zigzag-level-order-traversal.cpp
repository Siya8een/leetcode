class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        vector<vector<int>> ans;

        while (!q.empty()) {
            int s = q.size();
            vector<int> level(s);

            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int index = (leftToRight) ? i : s - 1 - i;
                level[index] = temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            ans.push_back(level);
            leftToRight = !leftToRight; // Switch the direction for the next level
        }

        return ans;
    }
};
