class Solution {
public:
    
    void dfs(vector<int> adjlist[],   vector <int >& vis,int count, int i){
          vis [i]=1;
         
          for ( auto it : adjlist[i]){
              if ( vis[it]==0)
              dfs (adjlist , vis,count, it);
          }
         
      }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adjlist[n];
        for ( int i =0;i < n ; i++ ){
             for ( int j =0; j < m ;j++){
                 if ( isConnected[i][j]== 1 && i != j){
                     adjlist[i].push_back(j);
                      adjlist[j].push_back(i);
                 }
             }
        }
        int count =0;
        vector <int > vis (n,0);
//         queue <int > q ;
//         q.push(0);
//         vis[0]=1;
        
//         while( !q.empty()){
//             int node = q.front();
//             q.pop();
          
//             for ( auto it : adjlist[node]){
//                 if ( !vis[it]){
//                     vis[it]=1;
//                     q.push(it);
//                 }
//             }
             
//         }
        
        for ( int i =0; i < vis.size(); i++){
            if ( !vis[i]){
                count++;
            dfs (adjlist ,vis,count , i);
            }
        }
        return count ;
    }
   
};