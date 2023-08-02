class Solution {
public:
   
    void  rotate_mat (vector<vector<int>>& mat){
         int n = mat.size();
        for ( int i=0;i<n;i++){
            for ( int j=i;j<n;j++){
                swap (mat[i][j],mat[j][i]);
            }
        }
        for ( int i=0;i < n;i++){
            reverse ( mat[i].begin(),mat[i].end());
        }
    }
    
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         int n = mat.size();
        if ( mat == target){
            return true;
        }
        for ( int i=0;i <= n;i++){
            rotate_mat(mat);
            if ( mat == target){
                return true;
            }
        }
        return false;
    }
};