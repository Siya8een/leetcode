#include <vector>

class Solution {
public:
    int solvebd(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }

    int coinChange(std::vector<int>& coins, int amount) {
        return solvebd(coins, amount);
    }
};
