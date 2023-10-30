class Solution {
public:
    bool dfs(int i, int color, int colors[], vector<vector<int>>& graph) {
        colors[i] = color;
        for (auto it : graph[i]) {
            if (colors[it] == -1) {
                if (!dfs(it, !color, colors, graph)) {
                    return false;
                }
            } else if (colors[it] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of vertices in the graph
        int colors[n]; // Initialize the colors array with -1

        for (int i = 0; i < n; i++) {
            colors[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, 0, colors, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};
