class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
        if (n < 0 || m < 0) {
            return INT_MAX; // Return a large value for out-of-bound cases
        }
        
        if (n == 0 && m == 0) {
            return grid[n][m];
        }
        
        if (dp[n][m] != -1) {
            return dp[n][m]; // Return the cached result if available
        }
        
        int up = solve(grid, n - 1, m, dp);
        int left = solve(grid, n, m - 1, dp);
        
        dp[n][m] = grid[n][m] + min(up, left); // Cache the result
        
        return dp[n][m];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization array
        
        return solve(grid, n - 1, m - 1, dp);
    }
};
