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
    TreeNode* create_map(TreeNode* root, int target, map<TreeNode*, TreeNode*>& parent) {
        TreeNode* res = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == target) {
                res = front;
            }

            if (front->left) {
                parent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                parent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }

   int burntree(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
    map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    q.push(root);
    vis[root] = true;
    int ans = 0;

    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left && !vis[front->left]) {
                q.push(front->left);
                vis[front->left] = true;
            }

            if (front->right && !vis[front->right]) {
                q.push(front->right);
                vis[front->right] = true;
            }

            if (parent[front] && !vis[parent[front]]) {
                q.push(parent[front]);
                vis[parent[front]] = true;
            }
        }

        if (!q.empty()) {
            ans++;
        }
    }

    return ans;
}


    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        TreeNode* target = create_map(root, start, parent);
        int time = burntree(target, parent);
        return time;
    }
};