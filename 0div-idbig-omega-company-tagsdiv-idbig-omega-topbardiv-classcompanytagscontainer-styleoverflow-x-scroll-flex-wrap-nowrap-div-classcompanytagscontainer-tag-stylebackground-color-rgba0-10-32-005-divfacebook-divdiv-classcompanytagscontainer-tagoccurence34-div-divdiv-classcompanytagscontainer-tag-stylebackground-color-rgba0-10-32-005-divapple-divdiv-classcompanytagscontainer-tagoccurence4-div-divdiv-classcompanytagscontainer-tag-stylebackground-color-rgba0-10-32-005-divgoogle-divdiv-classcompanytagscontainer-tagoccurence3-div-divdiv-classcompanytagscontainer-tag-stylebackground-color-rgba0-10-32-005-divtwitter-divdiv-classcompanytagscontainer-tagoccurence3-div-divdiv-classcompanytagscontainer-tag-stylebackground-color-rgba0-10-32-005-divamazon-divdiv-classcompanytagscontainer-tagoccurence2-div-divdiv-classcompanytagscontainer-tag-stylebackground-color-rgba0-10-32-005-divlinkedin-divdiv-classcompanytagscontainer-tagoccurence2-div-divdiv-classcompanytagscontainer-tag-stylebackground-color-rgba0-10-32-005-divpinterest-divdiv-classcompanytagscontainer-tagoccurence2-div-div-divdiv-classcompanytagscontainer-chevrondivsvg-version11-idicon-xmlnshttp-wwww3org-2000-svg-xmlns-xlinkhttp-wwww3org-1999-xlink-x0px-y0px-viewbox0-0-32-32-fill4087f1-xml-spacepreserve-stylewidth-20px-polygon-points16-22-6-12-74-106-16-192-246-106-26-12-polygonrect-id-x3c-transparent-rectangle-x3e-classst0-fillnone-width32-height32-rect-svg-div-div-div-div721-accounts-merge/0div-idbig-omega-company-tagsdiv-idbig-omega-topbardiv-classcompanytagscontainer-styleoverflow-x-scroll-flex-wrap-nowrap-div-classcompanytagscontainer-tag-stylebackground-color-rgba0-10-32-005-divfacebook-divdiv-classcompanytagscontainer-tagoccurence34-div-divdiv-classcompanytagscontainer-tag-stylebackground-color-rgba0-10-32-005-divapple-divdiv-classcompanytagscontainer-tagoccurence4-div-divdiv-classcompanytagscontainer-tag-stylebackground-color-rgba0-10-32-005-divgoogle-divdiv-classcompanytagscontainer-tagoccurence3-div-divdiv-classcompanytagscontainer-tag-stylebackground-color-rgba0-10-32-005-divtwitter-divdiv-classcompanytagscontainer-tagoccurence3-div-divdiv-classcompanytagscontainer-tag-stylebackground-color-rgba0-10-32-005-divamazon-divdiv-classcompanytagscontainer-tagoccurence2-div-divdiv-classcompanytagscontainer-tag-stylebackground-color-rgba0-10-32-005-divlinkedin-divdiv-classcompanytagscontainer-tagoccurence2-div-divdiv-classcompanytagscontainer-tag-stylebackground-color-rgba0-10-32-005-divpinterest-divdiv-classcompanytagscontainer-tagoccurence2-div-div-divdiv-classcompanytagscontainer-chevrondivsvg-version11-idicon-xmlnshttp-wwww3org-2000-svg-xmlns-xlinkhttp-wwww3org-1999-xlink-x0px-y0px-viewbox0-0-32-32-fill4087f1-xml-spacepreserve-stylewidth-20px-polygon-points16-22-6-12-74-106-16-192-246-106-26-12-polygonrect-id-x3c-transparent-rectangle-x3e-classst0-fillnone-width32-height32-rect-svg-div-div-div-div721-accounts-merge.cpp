#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet {

public:
    vector<int> parent, size, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int FindUPr(int node) {
        if (parent[node] == node) {
            return parent[node];
        }
        return parent[node] = FindUPr(parent[node]);
    }

   void UnionBySize(int u, int v) {
    int UPr_u = FindUPr(u);
    int UPr_v = FindUPr(v);
    if (UPr_u == UPr_v) {
        return;
    } else if (size[u] <= size[v]) {
        parent[UPr_u] = UPr_v; // Use UPr_u and UPr_v instead of u and v
        size[v] += size[UPr_u]; // Update the size accordingly
    } else {
        parent[UPr_v] = UPr_u; // Use UPr_u and UPr_v instead of u and v
        size[u] += size[UPr_v]; // Update the size accordingly
    }
}

void UnionByRank(int u, int v) {
    int UPr_u = FindUPr(u);
    int UPr_v = FindUPr(v);
    if (UPr_u == UPr_v) {
        return;
    }
    if (rank[UPr_u] < rank[UPr_v]) {
        parent[UPr_u] = UPr_v;
    } else {
        parent[UPr_v] = UPr_u;
        if (rank[UPr_u] == rank[UPr_v]) {
            rank[UPr_u]++;
        }
    }
}

};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.FindUPr(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
