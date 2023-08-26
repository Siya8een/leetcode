class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Start from the second-to-last row and update each cell with the minimum sum
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Update the current cell with the minimum sum of the two adjacent cells in the next row
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The top cell will have the minimum path sum
        return triangle[0][0];
    }
};
