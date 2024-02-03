#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int index, int prev, std::vector<int>& nums, std::vector<std::vector<int>>& memo) {
        if (index == nums.size() ) {
            return 0;
        }

        if (memo[index][prev+1] != -1) {
            return memo[index][prev+1];
        }

        int take = 0, notTake = 0;

        // Take the current element if it is greater than the previous element
        if (prev == -1 || (index < nums.size() && nums[index] > nums[prev])) {
            take = 1 + solve(index + 1, index, nums, memo);
        }

        // Skip the current element
        notTake = solve(index + 1, prev, nums, memo);

        memo[index][prev+1] = std::max(take, notTake);
        return memo[index][prev+1];
    }

    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        // Initialize memoization table with -1
        std::vector<std::vector<int>> memo(n , std::vector<int>(n + 1, -1));

        return solve(0 , -1, nums, memo);
    }
};
