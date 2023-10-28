class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSum;
        int sum = 0;
        prefixSum[0] = -1;  // Initialize with a prefix sum of 0 at index -1.

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (k != 0) {
                sum %= k;
            }
            
            if (prefixSum.find(sum) != prefixSum.end()) {
                if (i - prefixSum[sum] > 1) {
                    return true;
                }
            } else {
                prefixSum[sum] = i;
            }
        }

        return false;
    }
};
