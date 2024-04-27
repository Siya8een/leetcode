class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue < pair<int,int>> q;
        for ( int i =0;i < matrix.size();i++){
            for ( int j =0; j < matrix[0].size();j++){
                if ( matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i =0; i < matrix[0].size();i++){
                matrix[row][i]=0;
               
            }
             for (int i =0; i < matrix.size();i++){
               matrix[i][col]=0;
            }
        }

    }
};