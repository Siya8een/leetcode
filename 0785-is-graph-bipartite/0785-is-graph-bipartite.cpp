class Solution {
public:
bool solve(vector<vector<int>>& adj,vector<int>&color,int start){
    queue<int> pq;
    pq.push(start);
    color[start]=0;
    while(!pq.empty()){
        int node=pq.front();
        pq.pop();
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                pq.push(it);
            }
            else if(color[node]==color[it]){
return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        //  colour
      
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(solve(graph,color,i)==false)
                return false;
            }
            
        }
        return true;
    }
};