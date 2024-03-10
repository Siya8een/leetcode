class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum > goal && left < right) {
                sum -= nums[left];
                left++;
            }

            if (sum == goal) {
                ans++;

                // Count additional subarrays with the same sum
                int tempLeft = left;
                while (tempLeft < right && nums[tempLeft] == 0) {
                    ans++;
                    tempLeft++;
                }
            }

            right++;
        }

        return ans;
    }
};
