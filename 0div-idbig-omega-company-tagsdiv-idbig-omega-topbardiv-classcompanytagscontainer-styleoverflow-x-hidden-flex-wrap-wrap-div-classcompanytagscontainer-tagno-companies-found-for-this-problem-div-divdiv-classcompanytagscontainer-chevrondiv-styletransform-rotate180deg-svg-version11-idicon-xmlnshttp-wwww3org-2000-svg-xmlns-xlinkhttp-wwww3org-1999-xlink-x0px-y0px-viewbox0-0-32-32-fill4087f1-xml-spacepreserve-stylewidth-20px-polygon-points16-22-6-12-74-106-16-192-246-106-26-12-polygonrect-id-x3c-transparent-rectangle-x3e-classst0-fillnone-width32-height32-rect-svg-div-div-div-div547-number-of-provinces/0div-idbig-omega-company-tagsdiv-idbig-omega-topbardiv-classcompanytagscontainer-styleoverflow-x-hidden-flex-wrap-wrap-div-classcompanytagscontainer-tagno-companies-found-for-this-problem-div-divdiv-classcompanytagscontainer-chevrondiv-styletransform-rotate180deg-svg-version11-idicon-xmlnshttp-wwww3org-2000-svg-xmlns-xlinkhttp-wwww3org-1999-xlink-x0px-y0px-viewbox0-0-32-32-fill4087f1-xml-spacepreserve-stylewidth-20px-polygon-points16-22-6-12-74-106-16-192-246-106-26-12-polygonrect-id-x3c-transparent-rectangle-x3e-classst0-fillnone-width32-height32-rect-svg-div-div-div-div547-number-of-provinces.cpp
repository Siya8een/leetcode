class Solution {
    void dfs ( int start, vector <vector <int>> adjlis , int vis[]){
        
        vis[start]= 1;
        for ( auto it : adjlis[start]){
            if ( vis [it]!= 1){
              
                dfs ( it , adjlis, vis);
}
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int  n = isConnected.size();
         int  m =isConnected[0].size();
        // adjacency list
        vector <vector <int>> adjlis(n);
        for ( int i =0; i < n;i++){
             for ( int j =0 ; j < m ;j++){
                 if ( isConnected[i][j] ==1 && i != j){
                     adjlis[i].push_back(j);
                     adjlis[j].push_back(i);
                 }
             }
        }
        
        int V = adjlis.size();
        int vis[V];

        for (int i = 0; i < V; i++) {
            vis[i] = 0;
        }

        int count = 0;

        for (int i = 0; i < V; i++) {
            if (vis[i] != 1) {
                dfs(i, adjlis, vis);
                count++;
            }
        }

        return count;
    }
};