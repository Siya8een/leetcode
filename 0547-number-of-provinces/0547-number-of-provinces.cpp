class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjls) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjls);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<vector<int>> adjls(N);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(N, 0);
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, adjls);
            }
        }
        
        return count;
    }
};
