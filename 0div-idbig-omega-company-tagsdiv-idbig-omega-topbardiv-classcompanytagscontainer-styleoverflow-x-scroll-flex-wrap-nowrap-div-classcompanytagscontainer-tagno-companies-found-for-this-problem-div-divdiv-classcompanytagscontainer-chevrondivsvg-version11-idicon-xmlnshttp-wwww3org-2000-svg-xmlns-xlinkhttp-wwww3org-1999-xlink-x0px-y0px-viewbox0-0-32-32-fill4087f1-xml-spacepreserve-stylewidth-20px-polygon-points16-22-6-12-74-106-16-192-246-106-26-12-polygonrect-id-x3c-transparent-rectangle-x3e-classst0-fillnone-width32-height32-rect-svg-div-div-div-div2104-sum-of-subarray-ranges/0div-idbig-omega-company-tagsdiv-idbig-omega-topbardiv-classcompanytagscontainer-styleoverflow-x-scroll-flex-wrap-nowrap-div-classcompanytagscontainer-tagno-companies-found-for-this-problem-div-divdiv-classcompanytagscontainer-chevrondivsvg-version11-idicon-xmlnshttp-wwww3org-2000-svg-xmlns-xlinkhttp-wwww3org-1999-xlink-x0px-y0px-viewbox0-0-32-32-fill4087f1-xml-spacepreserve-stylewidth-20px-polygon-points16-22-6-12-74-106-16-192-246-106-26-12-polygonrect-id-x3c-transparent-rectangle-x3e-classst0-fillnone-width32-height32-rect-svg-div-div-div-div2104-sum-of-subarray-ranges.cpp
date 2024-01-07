#include <vector>

class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        int n = nums.size();
        long long rangeSum = 0;

        for (int i = 0; i < n; ++i) {
            int maxVal = nums[i];
            int minVal = nums[i];

            for (int j = i; j < n; ++j) {
                maxVal = std::max(maxVal, nums[j]);
                minVal = std::min(minVal, nums[j]);
                rangeSum += static_cast<long long>(maxVal) - minVal;
            }
        }

        return rangeSum;
    }
};
