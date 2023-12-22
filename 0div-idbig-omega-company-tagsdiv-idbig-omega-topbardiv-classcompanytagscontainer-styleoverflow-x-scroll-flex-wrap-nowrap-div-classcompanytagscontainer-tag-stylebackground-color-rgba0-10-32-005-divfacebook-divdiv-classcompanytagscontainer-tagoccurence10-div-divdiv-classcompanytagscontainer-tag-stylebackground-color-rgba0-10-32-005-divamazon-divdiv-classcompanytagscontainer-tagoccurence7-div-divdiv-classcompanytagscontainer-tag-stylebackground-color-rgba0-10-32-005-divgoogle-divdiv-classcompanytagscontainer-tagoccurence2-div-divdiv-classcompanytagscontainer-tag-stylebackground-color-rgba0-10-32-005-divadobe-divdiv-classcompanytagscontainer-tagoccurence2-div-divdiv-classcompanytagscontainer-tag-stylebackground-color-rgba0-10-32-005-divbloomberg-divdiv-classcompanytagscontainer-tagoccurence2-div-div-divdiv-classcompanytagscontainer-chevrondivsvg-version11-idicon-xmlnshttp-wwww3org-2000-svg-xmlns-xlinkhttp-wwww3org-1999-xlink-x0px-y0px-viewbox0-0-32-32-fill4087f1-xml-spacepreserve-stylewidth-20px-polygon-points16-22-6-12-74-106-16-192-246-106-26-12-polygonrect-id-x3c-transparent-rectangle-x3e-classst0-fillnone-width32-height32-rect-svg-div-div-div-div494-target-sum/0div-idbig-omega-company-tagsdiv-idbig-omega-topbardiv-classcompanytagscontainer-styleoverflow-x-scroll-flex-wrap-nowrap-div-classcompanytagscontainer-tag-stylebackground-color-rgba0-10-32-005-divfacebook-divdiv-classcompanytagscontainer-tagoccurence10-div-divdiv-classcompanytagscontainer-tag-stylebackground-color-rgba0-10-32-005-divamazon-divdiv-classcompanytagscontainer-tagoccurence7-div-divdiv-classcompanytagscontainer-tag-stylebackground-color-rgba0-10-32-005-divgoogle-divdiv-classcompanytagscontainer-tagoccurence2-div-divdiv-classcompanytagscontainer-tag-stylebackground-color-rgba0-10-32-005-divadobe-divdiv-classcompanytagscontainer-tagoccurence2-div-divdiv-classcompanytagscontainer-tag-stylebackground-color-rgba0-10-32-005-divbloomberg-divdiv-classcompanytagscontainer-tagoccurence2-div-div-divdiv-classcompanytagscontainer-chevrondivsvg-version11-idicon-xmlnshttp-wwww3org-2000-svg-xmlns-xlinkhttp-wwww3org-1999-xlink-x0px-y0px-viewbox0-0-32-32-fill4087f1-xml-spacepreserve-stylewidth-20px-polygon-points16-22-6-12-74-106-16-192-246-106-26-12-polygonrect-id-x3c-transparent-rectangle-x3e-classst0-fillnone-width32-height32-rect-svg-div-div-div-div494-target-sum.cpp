#include <vector>

class Solution {
public:
    void solve(vector<int>& nums, int target, int& count, int sum, int i) {
        if (i == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }

        // Include the current number with positive sign
        solve(nums, target, count, sum + nums[i], i + 1);

        // Include the current number with negative sign
        solve(nums, target, count, sum - nums[i], i + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        int i = 0;
        solve(nums, target, count, sum, i);
        return count;
    }
};
