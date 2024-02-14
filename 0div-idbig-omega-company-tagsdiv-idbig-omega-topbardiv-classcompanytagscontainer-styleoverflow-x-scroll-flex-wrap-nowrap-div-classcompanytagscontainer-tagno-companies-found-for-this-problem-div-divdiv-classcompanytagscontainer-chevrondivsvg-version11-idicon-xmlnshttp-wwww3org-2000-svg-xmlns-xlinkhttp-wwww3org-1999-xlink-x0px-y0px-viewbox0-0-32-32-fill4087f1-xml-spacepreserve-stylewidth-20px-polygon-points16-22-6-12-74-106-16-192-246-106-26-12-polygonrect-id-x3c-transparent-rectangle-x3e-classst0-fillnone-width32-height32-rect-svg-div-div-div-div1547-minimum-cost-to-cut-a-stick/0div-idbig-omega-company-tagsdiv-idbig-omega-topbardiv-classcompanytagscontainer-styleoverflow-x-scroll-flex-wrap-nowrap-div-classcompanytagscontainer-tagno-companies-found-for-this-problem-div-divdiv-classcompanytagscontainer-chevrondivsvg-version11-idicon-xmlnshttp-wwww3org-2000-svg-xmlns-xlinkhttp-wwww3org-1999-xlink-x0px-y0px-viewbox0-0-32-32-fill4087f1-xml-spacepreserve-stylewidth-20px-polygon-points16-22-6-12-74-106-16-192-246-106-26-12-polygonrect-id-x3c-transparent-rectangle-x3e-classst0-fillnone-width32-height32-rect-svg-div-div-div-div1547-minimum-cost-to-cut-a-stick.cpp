class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& memo) {
        // Base case: if the segment [i, j] is invalid
        if (i > j)
            return 0;

        // If the result for this segment is already computed, return it
        if (memo[i][j] != -1)
            return memo[i][j];

        int minCost = INT_MAX;

        // Try cutting the stick at each position between i and j
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts, memo) + solve(k + 1, j, cuts, memo);
            minCost = min(minCost, cost);
        }

        // Store the result for this segment in the memoization table
        memo[i][j] = minCost;
        return minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        // Add 0 and n to cuts as the starting and ending positions
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        // Initialize memoization table
        vector<vector<int>> memo(cuts.size(), vector<int>(cuts.size(), -1));

        // Call the recursive function to find the minimum cost
        return solve(1, cuts.size() - 2, cuts, memo);
    }
};
