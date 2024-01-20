#include <vector>
#include <climits>  // Include this for INT_MAX

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

        // Initialize the bottom row of dp with the corresponding values from the matrix
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            int col[] = {-1, 0, 1};
            for (int j = 0; j < n; j++) {
                int minVal = INT_MAX;  // Initialize to a large value

                for (int it = 0; it < 3; it++) {
                    int colr = col[it] + j;

                    if (colr >= 0 && colr < n) {
                        int value = matrix[i][j] + dp[i + 1][colr];
                        minVal = std::min(minVal, value);
                    }
                }

                dp[i][j] = minVal;
            }
        }

        // Find the minimum value in the first row (dp array)
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            minSum = std::min(minSum, dp[0][i]);
        }

        return minSum;
    }
};
