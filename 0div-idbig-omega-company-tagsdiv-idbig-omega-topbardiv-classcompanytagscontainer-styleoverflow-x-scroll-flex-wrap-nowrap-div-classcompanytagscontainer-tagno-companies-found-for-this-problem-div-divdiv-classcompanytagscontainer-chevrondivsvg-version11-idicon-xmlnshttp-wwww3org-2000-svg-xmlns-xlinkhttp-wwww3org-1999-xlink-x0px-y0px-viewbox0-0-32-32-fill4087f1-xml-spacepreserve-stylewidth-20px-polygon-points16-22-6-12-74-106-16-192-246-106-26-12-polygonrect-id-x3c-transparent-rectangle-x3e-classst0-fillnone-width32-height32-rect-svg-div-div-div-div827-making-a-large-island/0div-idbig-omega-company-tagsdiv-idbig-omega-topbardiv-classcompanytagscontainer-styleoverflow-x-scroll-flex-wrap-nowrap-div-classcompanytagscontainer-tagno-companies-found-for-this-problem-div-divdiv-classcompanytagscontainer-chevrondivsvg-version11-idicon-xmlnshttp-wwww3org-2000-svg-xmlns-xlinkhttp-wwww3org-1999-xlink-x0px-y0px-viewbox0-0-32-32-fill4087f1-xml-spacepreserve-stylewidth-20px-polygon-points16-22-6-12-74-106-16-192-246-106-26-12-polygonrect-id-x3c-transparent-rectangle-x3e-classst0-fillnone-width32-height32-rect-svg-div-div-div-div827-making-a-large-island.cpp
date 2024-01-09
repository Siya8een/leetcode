#include <vector>
#include <set>

using namespace std;

class DisjointSet {
  

public:
      vector<int> rank, size, parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int FindPr(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = FindPr(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int Upr_u = FindPr(u);
        int Upr_v = FindPr(v);

        if (Upr_u == Upr_v) {
            return;
        }

        if (size[Upr_u] < size[Upr_v]) {
            parent[Upr_u] = Upr_v;
            size[Upr_v] += size[Upr_u];
        } else {
            parent[Upr_v] = Upr_u;
            size[Upr_u] += size[Upr_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Create islands
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    int newrow[] = {-1, 0, 1, 0};
                    int newcol[] = {0, -1, 0, 1};
                    for (int i = 0; i < 4; i++) {
                        int newr = row + newrow[i];
                        int newc = col + newcol[i];
                        if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                            int nodeNo = row * n + col;
                            int adjnodeNo = newr * n + newc;
                            ds.UnionBySize(nodeNo, adjnodeNo);
                        }
                    }
                }
            }
        }

        int mx = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    continue;
                }

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;

                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];

                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(ds.FindPr(newr * n + newc));
                    }
                }

                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.FindPr(cellNo)]);
        }

        return mx;
    }

private:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
};
