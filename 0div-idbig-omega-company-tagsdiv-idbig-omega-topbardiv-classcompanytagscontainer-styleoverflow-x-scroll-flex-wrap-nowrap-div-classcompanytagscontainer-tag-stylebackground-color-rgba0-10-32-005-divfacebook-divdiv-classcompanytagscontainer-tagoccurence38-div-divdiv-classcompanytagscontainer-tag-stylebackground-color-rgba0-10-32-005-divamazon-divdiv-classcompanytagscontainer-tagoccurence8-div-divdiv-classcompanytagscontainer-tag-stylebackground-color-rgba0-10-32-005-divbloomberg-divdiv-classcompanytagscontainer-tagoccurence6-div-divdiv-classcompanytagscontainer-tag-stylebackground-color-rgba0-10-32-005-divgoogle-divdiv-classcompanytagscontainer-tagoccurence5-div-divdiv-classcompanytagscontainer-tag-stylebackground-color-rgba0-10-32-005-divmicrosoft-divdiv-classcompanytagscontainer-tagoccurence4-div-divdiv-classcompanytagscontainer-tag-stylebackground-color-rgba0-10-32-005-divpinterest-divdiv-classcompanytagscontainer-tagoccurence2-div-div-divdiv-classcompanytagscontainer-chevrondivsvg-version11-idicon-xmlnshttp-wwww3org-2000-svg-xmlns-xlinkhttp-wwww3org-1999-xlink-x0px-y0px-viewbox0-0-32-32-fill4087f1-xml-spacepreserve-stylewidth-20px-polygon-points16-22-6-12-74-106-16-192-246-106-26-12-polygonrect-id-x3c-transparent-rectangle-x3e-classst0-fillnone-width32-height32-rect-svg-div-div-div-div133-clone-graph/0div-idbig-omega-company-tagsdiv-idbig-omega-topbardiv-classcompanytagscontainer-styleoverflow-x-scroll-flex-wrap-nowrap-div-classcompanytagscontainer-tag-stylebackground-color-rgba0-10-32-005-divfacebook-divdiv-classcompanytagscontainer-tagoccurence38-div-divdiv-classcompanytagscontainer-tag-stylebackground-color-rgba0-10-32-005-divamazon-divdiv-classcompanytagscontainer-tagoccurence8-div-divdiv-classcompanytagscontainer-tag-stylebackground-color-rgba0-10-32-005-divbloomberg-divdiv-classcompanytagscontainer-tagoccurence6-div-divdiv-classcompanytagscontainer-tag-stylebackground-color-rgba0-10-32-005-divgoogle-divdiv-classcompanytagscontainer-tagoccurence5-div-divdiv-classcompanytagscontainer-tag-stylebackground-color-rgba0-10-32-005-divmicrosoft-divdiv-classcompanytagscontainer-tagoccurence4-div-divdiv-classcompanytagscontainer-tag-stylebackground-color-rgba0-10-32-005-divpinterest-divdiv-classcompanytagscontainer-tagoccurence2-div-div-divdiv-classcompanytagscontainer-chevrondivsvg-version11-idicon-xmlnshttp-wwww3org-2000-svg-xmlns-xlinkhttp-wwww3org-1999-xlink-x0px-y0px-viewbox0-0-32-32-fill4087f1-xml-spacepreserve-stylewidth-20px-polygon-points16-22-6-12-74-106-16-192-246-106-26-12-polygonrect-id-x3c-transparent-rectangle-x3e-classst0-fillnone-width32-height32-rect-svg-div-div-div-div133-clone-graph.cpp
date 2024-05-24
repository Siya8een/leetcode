// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Hash map to store the mapping from original node to the cloned node
        unordered_map<Node*, Node*> visited;

        // Initialize the queue with the start node
        queue<Node*> q;
        q.push(node);

        // Clone the start node and put it in the visited map
        visited[node] = new Node(node->val);

        // BFS traversal
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate through the neighbors of the current node
            for (Node* neighbor : curr->neighbors) {
                // If the neighbor hasn't been cloned yet
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor and put it in the visited map
                    visited[neighbor] = new Node(neighbor->val);
                    // Add the neighbor to the queue for further BFS
                    q.push(neighbor);
                }
                // Add the cloned neighbor to the current cloned node's neighbors
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        // Return the cloned node corresponding to the input node
        return visited[node];
    }
};
