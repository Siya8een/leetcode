/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        
        for (Node* child : root->children) {
            vector<int> childValues = postorder(child);
            ans.insert(ans.end(), childValues.begin(), childValues.end());
        }
        
        ans.push_back(root->val);
        return ans;
    }
};
