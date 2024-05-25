class Solution {
public:
    bool dfs(vector<int>& visited, vector<vector<int>>& adjlist, int index) {
        visited[index] = 1;  // Mark the current node as visiting (1)
        
        for (int neighbor : adjlist[index]) {
            if (visited[neighbor] == 1) {
                return false;  // Found a cycle
            }
            if (visited[neighbor] == 0) {
                if (!dfs(visited, adjlist, neighbor)) {
                    return false;  // Cycle detected in the recursive call
                }
            }
        }
        
        visited[index] = 2;  // Mark the current node as visited (2)
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto& pre : prerequisites) {
            adjlist[pre[1]].push_back(pre[0]);
        }
        
        vector<int> visited(numCourses, 0);  // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(visited, adjlist, i)) {
                    return false;  // Cycle detected
                }
            }
        }
        
        return true;  // No cycles detected, all courses can be finished
    }
};
