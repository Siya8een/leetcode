class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) {
            return nums[0];
        }
        if (n == 1) {
            return max(nums[0], nums[1]);
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int take = solve(n-2, nums, dp) + nums[n];
        int not_take = solve(n-1, nums, dp);
        
        dp[n] = max(take, not_take);
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        // Rob houses excluding the last house
        vector<int> nums1(nums.begin(), nums.end() - 1);
        int ans1 = solve(n-2, nums1, dp1);
        
        // Rob houses excluding the first house
        vector<int> nums2(nums.begin() + 1, nums.end());
        int ans2 = solve(n-2, nums2, dp2);
        
        return max(ans1, ans2);
    }
};
