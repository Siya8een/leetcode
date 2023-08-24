class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (m < 0 || n < 0) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize dp table with -1
        return solve(m - 1, n - 1, dp); // Start solving from bottom-right corner
    }
};
