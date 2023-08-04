class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int maxlength = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];

            if (sum == k) {
                maxlength = max(maxlength, i + 1);
                count++;
            }

            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()) {
                maxlength = max(maxlength, i - mpp[rem]);
                count += mpp[rem];
            }

            mpp[sum]++;
        }

        return count;
    }
};
