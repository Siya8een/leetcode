class Solution {
public:
    int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int d = triangle[i][j] + solve(triangle, dp, i + 1, j);
        int dg = triangle[i][j] + solve(triangle, dp, i + 1, j + 1);
        dp[i][j] = min(d, dg);
        
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));  // Updated initialization
        int i = 0;
        int j = 0;

        return solve(triangle, dp, i, j);
    }
};
