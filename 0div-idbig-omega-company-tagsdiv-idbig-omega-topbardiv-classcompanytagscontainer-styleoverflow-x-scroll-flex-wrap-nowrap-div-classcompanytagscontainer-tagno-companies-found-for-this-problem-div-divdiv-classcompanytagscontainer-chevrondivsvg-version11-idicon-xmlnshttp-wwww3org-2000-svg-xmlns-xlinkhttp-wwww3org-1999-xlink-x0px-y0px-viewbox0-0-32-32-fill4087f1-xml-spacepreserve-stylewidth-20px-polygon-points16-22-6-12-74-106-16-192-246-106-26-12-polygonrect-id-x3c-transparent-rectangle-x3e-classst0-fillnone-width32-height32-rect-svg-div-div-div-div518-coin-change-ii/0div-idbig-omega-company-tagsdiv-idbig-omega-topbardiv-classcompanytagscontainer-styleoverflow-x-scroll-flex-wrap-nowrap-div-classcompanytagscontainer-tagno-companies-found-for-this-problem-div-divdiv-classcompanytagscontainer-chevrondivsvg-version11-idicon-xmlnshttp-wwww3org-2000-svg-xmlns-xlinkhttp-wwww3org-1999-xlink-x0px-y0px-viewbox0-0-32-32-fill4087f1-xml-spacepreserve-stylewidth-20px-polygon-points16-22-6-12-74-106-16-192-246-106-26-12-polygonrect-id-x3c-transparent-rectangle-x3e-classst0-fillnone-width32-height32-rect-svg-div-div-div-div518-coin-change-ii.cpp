#include <vector>

class Solution {
public:
    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp) {
        if (amount == 0) {
            // Base case: combination found
            return 1;
        }

        if (index < 0) {
            // Base case: no more coins to consider
            return 0;
        }

        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        // Initialize count for the current combination
        int count = 0;

        // Take the current coin if it doesn't exceed the remaining amount
        if (amount >= coins[index]) {
            count += solve(amount - coins[index], coins, index, dp);
        }

        // Move to the next coin (do not take the current coin)
        count += solve(amount, coins, index - 1, dp);

        // Save the result in the memoization table
        dp[index][amount] = count;

        return count;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(amount, coins, n - 1, dp);
    }
};
