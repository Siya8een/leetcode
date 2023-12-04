class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }

        int s = sum / 2;
        int n = nums.size();
        vector<bool> dp(s + 1, false);

        dp[0] = true;

        if (nums[0] <= s) {
            dp[nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int target = s; target >= nums[i]; target--) {
                dp[target] = dp[target] || dp[target - nums[i]];
            }
        }

        return dp[s];
    }
};
