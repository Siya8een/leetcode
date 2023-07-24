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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> verticalOrder;
        map<int, map<int, vector<int>>> nodes; // map to store nodes based on their horizontal distance and level
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root == nullptr)
            return verticalOrder;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first; // horizontal distance
            int lvl = temp.second.second; // level

            nodes[hd][lvl].push_back(frontNode->val);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto it1 : nodes) {
            vector<int> verticalColumn;
            for (auto it2 : it1.second) {
                vector<int>& nodesInLevel = it2.second;
                sort(nodesInLevel.begin(), nodesInLevel.end());
                verticalColumn.insert(verticalColumn.end(), nodesInLevel.begin(), nodesInLevel.end());
            }
            verticalOrder.push_back(verticalColumn);
        }

        return verticalOrder;
    }
};
