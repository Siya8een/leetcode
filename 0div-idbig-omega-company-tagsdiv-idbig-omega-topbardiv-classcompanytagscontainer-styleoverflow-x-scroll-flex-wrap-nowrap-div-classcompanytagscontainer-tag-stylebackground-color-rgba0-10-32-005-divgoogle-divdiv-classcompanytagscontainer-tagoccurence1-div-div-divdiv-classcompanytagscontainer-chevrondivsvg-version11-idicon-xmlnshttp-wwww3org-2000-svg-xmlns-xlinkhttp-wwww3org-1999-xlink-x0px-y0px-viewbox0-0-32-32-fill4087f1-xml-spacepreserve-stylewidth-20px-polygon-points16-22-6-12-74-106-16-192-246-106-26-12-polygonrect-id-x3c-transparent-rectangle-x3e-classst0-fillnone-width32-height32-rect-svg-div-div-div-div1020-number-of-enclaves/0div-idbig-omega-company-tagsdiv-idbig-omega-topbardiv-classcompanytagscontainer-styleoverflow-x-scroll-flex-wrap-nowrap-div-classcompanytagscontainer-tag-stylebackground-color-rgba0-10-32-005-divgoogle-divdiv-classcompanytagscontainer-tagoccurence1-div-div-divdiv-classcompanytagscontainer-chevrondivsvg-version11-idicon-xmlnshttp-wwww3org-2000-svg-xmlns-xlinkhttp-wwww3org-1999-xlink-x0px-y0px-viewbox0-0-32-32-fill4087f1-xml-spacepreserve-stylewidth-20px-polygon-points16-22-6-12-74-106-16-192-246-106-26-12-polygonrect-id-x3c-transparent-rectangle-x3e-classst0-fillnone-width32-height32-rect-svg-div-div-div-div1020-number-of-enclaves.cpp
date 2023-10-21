#include <vector>
#include <queue>

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        std::queue<std::pair<int, int>> q;

        // Traverse the boundary
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                vis[0][j] = 1;
                q.push({0, j});
            }
            if (grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                vis[n - 1][j] = 1;
                q.push({n - 1, j});
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = current.first + dx[i];
                int newCol = current.second + dy[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }

        int count = 0;

        // Count the number of unvisited '1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
