class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Create a copy of the input matrix to store intermediate results
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the first row of dp matrix with the same values as the first row of the input matrix
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        
        // Iterate through the matrix row by row, calculating the minimum falling path sum
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] + min({
                    dp[i - 1][j], // directly below
                    (j > 0) ? dp[i - 1][j - 1] : INT_MAX, // diagonally left
                    (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX // diagonally right
                });
            }
        }
        
        // Find the minimum sum in the last row of dp matrix, which represents the minimum falling path sums
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            minSum = min(minSum, dp[n - 1][i]);
        }
        
        return minSum;
    }
};