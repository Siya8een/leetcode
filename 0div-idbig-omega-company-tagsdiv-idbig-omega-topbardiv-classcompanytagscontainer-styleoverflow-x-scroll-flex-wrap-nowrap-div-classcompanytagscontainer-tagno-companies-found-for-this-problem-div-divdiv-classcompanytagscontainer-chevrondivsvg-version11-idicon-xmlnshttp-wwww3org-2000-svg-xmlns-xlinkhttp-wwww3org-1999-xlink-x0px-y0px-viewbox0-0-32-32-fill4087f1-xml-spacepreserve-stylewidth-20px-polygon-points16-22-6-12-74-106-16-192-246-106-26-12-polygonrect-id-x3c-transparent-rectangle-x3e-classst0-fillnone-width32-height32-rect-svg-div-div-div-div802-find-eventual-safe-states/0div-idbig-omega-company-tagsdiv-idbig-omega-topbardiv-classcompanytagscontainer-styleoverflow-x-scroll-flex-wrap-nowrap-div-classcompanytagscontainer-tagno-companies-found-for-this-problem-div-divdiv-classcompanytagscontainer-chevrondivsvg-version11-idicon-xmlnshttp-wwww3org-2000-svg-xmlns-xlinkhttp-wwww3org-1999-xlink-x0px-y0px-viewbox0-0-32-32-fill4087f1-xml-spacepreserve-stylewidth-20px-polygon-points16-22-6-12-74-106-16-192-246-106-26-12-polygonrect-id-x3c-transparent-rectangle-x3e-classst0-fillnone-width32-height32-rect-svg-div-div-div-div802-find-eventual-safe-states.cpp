class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V, 0);
        vector<vector<int>> reversedGraph(V);
        
        // Create the reversed graph and calculate in-degrees
        for (int i = 0; i < V; i++) {
            for (int neighbor : graph[i]) {
                reversedGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        
        vector<int> safeNodes;
        stack<int> stack;
        
        // Add nodes with in-degree 0 to the stack
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                stack.push(i);
            }
        }
        
        // Perform a modified DFS
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            safeNodes.push_back(node);
            
            for (int neighbor : reversedGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    stack.push(neighbor);
                }
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
