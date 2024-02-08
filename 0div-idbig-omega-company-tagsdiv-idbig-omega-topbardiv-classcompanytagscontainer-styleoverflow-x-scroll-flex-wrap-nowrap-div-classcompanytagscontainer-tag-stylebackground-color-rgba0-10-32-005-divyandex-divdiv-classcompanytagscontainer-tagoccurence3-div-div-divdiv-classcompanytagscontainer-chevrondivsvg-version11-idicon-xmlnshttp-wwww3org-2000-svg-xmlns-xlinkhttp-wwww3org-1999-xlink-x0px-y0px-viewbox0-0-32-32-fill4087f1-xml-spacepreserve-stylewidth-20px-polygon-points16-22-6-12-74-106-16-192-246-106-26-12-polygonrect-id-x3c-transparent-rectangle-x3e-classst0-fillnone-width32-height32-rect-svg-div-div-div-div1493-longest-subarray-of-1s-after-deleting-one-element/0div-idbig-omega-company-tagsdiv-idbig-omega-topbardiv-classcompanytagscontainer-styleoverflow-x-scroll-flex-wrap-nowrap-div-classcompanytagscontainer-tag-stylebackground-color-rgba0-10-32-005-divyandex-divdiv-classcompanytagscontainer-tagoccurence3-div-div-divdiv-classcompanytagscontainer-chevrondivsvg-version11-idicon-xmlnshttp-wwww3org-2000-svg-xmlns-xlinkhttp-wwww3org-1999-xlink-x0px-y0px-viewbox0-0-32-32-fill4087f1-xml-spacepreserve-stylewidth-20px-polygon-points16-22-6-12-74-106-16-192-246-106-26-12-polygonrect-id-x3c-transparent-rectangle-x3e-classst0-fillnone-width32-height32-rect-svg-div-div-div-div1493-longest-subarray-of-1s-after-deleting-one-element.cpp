#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int max_count = 0;
        int count = 0;
        int count0 = 0;
        int j = 0; // Initialize j here

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                count0++;
                while (count0 > 1) {
                    if (nums[j] == 0) {
                        count0--;
                    }
                    j++; // Move j to next position
                }
            }
            count++;
            max_count = std::max(max_count, i - j ); // Update max_count
        }

        return max_count; // Return max_count without subtracting 1
    }
};
