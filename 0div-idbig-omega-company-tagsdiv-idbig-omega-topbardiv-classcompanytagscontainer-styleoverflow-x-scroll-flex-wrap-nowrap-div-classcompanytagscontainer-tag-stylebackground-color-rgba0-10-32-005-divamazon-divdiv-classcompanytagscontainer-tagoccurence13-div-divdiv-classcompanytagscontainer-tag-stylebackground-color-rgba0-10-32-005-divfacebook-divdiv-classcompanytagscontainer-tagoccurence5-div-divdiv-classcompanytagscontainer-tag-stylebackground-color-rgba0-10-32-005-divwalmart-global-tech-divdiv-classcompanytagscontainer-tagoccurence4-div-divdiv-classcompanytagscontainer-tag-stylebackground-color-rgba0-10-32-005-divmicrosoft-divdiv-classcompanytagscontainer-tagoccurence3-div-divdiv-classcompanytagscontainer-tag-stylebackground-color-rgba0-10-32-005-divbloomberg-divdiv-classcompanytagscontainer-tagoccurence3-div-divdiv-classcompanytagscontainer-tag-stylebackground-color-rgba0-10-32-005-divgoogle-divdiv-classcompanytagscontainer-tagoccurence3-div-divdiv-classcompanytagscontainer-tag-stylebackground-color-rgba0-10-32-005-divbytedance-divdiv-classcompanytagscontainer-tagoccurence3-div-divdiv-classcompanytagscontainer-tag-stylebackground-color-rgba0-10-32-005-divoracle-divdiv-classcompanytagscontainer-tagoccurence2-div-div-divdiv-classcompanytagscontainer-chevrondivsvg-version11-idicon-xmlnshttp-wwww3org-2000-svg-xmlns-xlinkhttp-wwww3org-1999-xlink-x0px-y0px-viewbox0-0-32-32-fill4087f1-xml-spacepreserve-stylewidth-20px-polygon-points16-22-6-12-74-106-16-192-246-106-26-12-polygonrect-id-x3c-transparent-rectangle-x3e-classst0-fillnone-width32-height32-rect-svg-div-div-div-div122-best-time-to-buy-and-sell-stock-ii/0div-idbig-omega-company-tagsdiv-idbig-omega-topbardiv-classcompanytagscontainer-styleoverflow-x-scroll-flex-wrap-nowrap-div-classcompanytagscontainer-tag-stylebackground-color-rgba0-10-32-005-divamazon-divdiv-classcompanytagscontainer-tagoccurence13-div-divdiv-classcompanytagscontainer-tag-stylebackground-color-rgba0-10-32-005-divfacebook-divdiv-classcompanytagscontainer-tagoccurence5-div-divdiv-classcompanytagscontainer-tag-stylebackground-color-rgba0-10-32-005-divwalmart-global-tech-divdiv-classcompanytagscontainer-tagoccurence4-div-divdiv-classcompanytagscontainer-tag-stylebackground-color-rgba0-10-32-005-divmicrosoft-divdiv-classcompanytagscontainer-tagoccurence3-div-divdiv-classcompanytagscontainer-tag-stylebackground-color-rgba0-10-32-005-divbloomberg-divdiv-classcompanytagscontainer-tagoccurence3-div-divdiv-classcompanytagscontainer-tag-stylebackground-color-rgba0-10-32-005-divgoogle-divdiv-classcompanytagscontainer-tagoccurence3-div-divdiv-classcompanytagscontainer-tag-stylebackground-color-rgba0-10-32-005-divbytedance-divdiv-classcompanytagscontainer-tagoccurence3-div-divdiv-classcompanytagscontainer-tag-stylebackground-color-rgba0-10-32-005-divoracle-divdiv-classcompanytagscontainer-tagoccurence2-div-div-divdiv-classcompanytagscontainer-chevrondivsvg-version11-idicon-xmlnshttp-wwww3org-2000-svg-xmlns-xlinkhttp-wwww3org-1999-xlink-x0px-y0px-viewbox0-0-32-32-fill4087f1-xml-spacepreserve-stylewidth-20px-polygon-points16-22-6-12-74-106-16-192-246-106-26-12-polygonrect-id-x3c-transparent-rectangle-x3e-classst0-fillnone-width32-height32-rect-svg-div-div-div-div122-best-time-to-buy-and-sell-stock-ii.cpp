class Solution {
public:
    int solve(int canbuy, vector<int>& prices, int index,vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[canbuy][index] != -1) {
            return dp[canbuy][index];
        }

        int a = 0, b = 0;
  int profit = 0;
        if (canbuy == 1) {
            // Buy or skip buying
            profit = max(-prices[index] + solve(0, prices, index + 1,  dp), solve(1, prices, index + 1, dp));
        } else {
            // Sell or skip selling
            profit = max(prices[index] + solve(1, prices, index + 1,  dp), solve(0, prices, index + 1, dp));
        }

      
        dp[canbuy][index] = profit;

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int canbuy = 1;
      
        vector<vector<int>> dp(canbuy + 1, vector<int>(prices.size(), -1));
        return solve(canbuy, prices, 0,  dp);
    }
};
