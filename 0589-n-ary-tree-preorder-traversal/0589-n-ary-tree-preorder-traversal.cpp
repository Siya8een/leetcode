class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        
        ans.push_back(root->val);

        for (Node* child : root->children) {
            vector<int> childValues = preorder(child);
            ans.insert(ans.end(), childValues.begin(), childValues.end());
        }

        return ans;
    }
};
