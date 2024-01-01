
class DisjointSet {
    
public:
    std::vector<int> parent, size;

    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int FindUPr(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = FindUPr(parent[node]); // Path compression
    }

    void UnionBySize(int u, int v) {
        int UPr_u = FindUPr(u);
        int UPr_v = FindUPr(v);
        if (UPr_v == UPr_u) {
            return;
        }
        if (size[UPr_u] < size[UPr_v]) {
            parent[UPr_u] = UPr_v;
            size[UPr_v]+= size[UPr_u];
        } else {
             parent[UPr_v] = UPr_u;
            size[UPr_u] += size[UPr_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    DisjointSet ds(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                ds.UnionBySize(i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ds.FindUPr(i) == i) {
            cnt++;
        }
    }

    return n - cnt;
}

};