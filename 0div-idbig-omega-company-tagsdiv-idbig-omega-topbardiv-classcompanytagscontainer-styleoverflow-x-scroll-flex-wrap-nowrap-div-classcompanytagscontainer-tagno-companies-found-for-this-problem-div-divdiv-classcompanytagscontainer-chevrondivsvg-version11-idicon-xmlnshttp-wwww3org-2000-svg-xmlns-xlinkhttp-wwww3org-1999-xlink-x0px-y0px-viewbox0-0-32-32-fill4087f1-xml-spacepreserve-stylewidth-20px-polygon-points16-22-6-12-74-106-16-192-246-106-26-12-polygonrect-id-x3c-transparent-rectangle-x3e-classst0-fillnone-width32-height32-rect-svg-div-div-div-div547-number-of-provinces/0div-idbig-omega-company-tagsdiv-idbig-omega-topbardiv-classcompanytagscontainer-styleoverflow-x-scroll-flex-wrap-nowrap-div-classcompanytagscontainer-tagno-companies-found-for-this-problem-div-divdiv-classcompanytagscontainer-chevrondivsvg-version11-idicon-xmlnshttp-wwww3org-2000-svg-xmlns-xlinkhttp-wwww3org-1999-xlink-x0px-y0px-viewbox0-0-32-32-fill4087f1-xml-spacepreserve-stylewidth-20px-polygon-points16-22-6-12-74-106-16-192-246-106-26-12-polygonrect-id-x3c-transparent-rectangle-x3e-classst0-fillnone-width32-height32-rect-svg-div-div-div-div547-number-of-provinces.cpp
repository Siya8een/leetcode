class Solution {
public:
    
   void dfs(int i, vector<int>& vis, vector<vector<int>>& adjList) {
        vis[i] = 1;
        for (int neighbor : adjList[i]) {
            if (vis[neighbor] == 0) {
                dfs(neighbor, vis, adjList);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
    // creating an. adjacency list 
         vector < int > vis ( n, 0);
        vector < vector < int >> adjlis(n);
         for ( int i =0 ;i < isConnected.size();i++){
             for ( int j =0 ; j < isConnected[0].size();j++){
                 if ( i != j &&  isConnected[i][j]==1){
                  adjlis[i].push_back( j);
                     adjlis[j].push_back(i);
                 }
             }
         }
        
        int count =0;
        for ( int i =0 ; i < vis.size();i++){
            if ( vis[i]!= 1){    
                count ++;
                vis[i]= 1;
                 dfs ( i , vis ,adjlis);
            }
        }
        
        
        return count ;
    }
};