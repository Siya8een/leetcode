class Solution {
public:
    int solve(int index, bool buying, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][buying] != -1) {
            return dp[index][buying];
        }

        if (buying) {
            // If we have a stock, we can either sell it or do nothing
            int sell = prices[index] + solve(index + 1, false, prices, dp);
            int noAction = solve(index + 1, true, prices, dp);
            dp[index][buying] = max(sell, noAction);
        } else {
            // If we don't have a stock, we can either buy one or do nothing
            int buy = -prices[index] + solve(index + 1, true, prices, dp);
            int noAction = solve(index + 1, false, prices, dp);
            dp[index][buying] = max(buy, noAction);
        }

        return dp[index][buying];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, false, prices, dp);
    }
};
