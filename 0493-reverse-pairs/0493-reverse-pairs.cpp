#include <vector>

class Solution {
public:
    int mergeSortAndCount(std::vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j])
                j++;
            count += (j - mid - 1);
        }

        std::sort(nums.begin() + left, nums.begin() + right + 1);

        return count;
    }

    int reversePairs(std::vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
};
