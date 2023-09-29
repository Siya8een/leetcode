#include <vector>
#include <utility> // Include the utility header for pair

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Find the positions of zeros in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    ans.push_back(std::make_pair(i, j));
            }
        }

        // Set entire rows and columns to zero based on the positions of zeros
        for (int i = 0; i < ans.size(); i++) {
            int row = ans[i].first;
            int col = ans[i].second;

            for (int j = 0; j < cols; j++) {
                matrix[row][j] = 0;
            }

            for (int j = 0; j < rows; j++) {
                matrix[j][col] = 0;
            }
        }
    }
};
