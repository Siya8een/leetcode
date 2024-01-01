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
    int makeConnected(int n, vector<vector<int>>& connections) {
        

        DisjointSet ds(n);
       int cntExtras =0;
         for ( auto it : connections ){
             int u = it [0];
             int v = it [1];
             if ( ds.FindUPr(u) == ds.FindUPr(v)){
                 cntExtras++;
             }
             else {
                  ds. UnionBySize(u,v);
             }
         }
        int cntC=0;
        for ( int i =0; i < n ;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }
            int ans = cntC -1;
            if ( cntExtras>=ans){
                return ans;
            }
            return -1;
        
    }
};