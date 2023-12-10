class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Initialize matrix2 with dimensions swapped
        vector<vector<int>> matrix2(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix2[j][i] = matrix[i][j];
            }
        }

        return matrix2;
    }
};
