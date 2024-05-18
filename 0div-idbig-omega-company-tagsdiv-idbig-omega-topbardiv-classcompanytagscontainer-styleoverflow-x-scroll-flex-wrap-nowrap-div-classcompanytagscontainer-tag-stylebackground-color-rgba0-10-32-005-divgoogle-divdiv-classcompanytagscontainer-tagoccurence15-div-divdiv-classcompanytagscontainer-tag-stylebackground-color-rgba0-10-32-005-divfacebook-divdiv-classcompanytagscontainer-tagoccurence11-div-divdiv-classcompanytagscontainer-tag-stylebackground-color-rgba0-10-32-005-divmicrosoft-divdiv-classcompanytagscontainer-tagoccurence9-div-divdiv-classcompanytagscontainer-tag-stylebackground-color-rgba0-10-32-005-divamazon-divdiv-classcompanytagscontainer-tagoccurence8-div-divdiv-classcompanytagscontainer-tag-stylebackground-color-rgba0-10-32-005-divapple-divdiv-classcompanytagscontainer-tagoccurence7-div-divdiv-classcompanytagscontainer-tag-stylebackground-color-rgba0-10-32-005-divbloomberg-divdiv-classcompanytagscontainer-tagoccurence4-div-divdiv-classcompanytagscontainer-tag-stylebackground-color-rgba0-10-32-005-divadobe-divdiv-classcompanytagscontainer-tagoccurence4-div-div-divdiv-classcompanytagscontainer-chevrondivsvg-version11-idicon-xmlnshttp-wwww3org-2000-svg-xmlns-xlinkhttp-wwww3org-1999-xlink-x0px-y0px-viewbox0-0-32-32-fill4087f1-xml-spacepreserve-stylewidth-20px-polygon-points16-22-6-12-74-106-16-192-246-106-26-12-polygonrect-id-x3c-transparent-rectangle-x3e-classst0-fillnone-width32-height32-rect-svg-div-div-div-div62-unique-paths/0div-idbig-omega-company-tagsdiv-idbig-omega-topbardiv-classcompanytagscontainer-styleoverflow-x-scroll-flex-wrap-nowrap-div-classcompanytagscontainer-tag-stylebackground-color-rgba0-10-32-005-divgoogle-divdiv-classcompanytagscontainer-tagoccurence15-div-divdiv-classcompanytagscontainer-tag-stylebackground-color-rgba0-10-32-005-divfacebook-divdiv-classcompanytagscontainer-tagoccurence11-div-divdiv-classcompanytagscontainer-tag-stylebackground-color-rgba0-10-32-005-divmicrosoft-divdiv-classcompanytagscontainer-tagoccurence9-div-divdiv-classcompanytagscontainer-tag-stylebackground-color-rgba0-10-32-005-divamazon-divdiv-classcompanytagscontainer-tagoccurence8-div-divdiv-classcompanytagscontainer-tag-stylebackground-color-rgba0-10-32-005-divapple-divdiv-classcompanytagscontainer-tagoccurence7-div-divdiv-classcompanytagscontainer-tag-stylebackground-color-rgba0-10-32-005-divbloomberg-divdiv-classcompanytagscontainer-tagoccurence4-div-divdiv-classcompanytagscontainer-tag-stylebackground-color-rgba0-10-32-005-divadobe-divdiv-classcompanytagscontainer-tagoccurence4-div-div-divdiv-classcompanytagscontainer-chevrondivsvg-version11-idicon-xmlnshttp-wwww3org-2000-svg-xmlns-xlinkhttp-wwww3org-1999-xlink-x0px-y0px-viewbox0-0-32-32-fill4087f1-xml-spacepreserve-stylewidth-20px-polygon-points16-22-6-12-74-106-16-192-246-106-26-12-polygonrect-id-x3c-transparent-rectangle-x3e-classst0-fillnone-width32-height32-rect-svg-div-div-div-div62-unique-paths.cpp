class Solution {
public:
    int solve(vector<vector<int>>& dp, int m, int n, int i, int j) {
        // Base case: if we've reached the bottom-right corner, return 1
        if (i == m-1 && j == n-1) {
            return 1;
        }
        
        // If the value is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int rightPaths = 0, downPaths = 0;
        
        // Move right
        if (j + 1 < n) {
            rightPaths = solve(dp, m, n, i, j + 1);
        }
        
        // Move down
        if (i + 1 < m) {
            downPaths = solve(dp, m, n, i + 1, j);
        }
        
        // Sum up the paths from right and down moves
        dp[i][j] = rightPaths + downPaths;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, m, n, 0, 0);
    }
};
