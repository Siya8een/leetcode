#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Check if the start and destination cells are blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        pair<int, int> src = {0, 0};
        pair<int, int> destination = {n - 1, n - 1};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        dist[src.first][src.second] = 1; // Starting with the first cell
        q.push({1, {src.first, src.second}}); // {dist, {row, col}}

        // Possible moves in 8 directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int distnode = node.first;
            int r = node.second.first;
            int c = node.second.second;

            if (r == destination.first && c == destination.second) {
                return distnode;
            }

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                    grid[newr][newc] == 0 && distnode + 1 < dist[newr][newc]) {
                    dist[newr][newc] = distnode + 1;
                    q.push({dist[newr][newc], {newr, newc}});
                }
            }
        }

        return -1;
    }
};
