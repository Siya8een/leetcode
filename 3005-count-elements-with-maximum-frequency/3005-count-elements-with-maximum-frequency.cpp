#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> mpp;
        int maxfreq = 0;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            maxfreq = std::max(maxfreq, mpp[nums[i]]);
        }

        int count = 0;
        for (const auto& pair : mpp) {
            if (pair.second == maxfreq) {
                count += pair.second; // Add the frequency of elements with the maximum frequency
            }
        }

        return count;
    }
};
