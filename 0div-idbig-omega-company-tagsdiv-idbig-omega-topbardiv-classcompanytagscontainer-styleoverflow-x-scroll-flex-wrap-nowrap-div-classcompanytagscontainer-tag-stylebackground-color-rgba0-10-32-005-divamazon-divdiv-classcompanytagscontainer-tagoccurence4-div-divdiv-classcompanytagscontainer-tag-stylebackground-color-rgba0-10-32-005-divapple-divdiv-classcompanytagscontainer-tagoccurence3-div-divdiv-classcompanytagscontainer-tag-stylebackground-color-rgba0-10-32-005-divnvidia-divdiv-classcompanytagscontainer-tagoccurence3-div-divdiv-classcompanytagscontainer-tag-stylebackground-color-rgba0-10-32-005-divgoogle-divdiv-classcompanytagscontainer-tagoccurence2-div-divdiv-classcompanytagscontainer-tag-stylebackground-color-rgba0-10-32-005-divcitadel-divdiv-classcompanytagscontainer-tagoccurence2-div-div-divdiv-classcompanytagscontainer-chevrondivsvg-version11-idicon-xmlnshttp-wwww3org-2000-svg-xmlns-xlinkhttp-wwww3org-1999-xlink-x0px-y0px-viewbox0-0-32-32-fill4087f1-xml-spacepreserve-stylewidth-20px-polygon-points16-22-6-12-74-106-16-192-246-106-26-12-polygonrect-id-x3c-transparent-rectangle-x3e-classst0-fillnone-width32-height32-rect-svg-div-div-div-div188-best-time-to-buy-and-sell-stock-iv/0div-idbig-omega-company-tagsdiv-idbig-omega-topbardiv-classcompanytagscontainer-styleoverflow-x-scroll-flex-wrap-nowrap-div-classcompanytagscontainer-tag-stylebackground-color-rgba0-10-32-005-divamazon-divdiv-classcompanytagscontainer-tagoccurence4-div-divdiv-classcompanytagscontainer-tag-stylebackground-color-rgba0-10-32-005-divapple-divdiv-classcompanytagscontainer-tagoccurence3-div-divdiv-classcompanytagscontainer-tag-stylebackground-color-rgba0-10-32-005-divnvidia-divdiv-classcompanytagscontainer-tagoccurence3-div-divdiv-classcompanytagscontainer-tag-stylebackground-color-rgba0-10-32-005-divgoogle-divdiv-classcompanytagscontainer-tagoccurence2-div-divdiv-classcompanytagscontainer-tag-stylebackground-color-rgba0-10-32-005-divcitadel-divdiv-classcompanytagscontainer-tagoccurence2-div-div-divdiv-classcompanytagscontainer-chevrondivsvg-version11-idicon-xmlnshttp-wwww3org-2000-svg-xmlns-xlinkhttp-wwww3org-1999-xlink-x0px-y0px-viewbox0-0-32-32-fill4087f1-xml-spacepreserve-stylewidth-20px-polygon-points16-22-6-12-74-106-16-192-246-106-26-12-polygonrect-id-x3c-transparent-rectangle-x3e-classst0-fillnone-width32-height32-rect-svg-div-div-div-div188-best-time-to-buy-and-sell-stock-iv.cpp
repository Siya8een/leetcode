#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) {
            return 0;
        }

        // If k is large enough, it allows us to perform as many transactions as we want
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        // dp[i][j][0] represents the maximum profit on day i with j transactions and not holding any stock
        // dp[i][j][1] represents the maximum profit on day i with j transactions and holding a stock
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(k + 1, std::vector<int>(2, 0)));

        for (int i = 0; i <= k; ++i) {
            dp[0][i][1] = -prices[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                // No transaction on the i-th day
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

                // Perform a transaction on the i-th day
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};
