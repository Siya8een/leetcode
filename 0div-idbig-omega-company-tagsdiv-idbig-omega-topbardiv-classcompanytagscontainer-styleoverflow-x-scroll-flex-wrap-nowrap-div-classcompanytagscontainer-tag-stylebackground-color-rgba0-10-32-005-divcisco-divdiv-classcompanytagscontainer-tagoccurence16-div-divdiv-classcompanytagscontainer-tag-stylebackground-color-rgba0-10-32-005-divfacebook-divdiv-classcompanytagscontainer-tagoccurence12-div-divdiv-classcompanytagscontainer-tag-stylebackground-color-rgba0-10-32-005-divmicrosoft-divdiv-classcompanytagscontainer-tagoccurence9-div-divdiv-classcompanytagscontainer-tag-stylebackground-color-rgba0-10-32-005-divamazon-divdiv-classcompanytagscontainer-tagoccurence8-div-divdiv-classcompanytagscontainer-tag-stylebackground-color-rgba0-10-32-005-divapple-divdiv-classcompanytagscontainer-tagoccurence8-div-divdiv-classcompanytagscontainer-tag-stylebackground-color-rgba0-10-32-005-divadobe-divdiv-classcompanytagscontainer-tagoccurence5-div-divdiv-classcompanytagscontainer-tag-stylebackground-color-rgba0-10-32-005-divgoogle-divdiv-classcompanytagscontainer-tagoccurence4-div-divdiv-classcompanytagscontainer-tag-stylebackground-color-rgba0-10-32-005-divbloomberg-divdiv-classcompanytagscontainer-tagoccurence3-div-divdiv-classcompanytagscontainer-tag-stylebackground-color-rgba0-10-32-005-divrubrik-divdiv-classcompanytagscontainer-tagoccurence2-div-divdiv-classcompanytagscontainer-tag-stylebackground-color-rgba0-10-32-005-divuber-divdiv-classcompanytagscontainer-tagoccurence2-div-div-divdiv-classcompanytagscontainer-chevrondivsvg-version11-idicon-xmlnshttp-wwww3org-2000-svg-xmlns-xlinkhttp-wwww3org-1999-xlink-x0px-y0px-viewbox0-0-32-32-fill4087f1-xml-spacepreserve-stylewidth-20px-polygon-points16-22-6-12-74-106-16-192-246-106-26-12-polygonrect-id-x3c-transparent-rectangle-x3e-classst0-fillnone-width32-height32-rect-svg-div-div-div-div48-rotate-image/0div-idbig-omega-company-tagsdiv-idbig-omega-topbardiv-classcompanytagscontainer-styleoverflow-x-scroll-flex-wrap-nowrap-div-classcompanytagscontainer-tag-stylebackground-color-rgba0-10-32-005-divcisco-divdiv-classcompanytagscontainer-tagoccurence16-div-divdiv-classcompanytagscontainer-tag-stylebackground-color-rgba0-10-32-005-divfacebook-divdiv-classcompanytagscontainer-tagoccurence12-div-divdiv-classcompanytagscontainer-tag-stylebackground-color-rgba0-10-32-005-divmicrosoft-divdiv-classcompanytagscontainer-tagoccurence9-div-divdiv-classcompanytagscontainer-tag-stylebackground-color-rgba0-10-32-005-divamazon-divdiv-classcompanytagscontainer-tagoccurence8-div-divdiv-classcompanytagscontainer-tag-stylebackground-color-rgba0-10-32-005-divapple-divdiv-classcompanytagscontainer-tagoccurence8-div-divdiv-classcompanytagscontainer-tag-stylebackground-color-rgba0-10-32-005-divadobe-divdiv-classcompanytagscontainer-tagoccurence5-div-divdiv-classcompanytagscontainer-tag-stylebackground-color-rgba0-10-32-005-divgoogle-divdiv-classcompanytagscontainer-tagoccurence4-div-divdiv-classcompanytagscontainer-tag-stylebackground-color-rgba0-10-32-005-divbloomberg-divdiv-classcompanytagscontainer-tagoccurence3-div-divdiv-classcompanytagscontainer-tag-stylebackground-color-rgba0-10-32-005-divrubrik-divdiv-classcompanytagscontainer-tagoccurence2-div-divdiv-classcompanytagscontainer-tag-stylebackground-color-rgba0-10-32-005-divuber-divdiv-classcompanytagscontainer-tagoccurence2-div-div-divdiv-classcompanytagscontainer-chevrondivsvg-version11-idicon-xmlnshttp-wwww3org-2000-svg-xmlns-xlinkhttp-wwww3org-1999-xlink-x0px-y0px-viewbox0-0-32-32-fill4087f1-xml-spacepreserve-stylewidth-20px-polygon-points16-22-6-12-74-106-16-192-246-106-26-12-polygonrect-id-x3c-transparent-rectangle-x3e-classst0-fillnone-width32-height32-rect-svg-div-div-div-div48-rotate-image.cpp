class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for ( int i =0; i < matrix.size();i++){
            for ( int j =i; j < matrix[0].size();j++){
                int a =matrix[i][j];
                int b = matrix[j][i];
                matrix[i][j]= b;
                matrix[j][i]= a;
            }
        }
          for (int i = 0; i < matrix[0].size(); i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    }
};