class Solution {
public:
//     int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
//         if (i == triangle.size() - 1) {
//             return triangle[i][j];
//         }
        
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int d = triangle[i][j] + solve(triangle, dp, i + 1, j);
//         int dg = triangle[i][j] + solve(triangle, dp, i + 1, j + 1);
//         dp[i][j] = min(d, dg);
        
//         return dp[i][j];
//     }

  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));

    // Initialize the bottom row of dp
    for (int i = 0; i < triangle.size(); i++) {
        dp[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
    }

    // Bottom-up dynamic programming
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {  // Corrected loop condition
            int d = triangle[i][j] + dp[i + 1][j];
            int dg = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(d, dg);
        }
    }

    return dp[0][0];
}
};
