
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> countMap;

        // Count the occurrences of each element
        for (int num : nums) {
            countMap[num]++;
        }

        int threshold = nums.size() / 3;

        // Check if an element appears more than n/3 times
        for (const auto& pair : countMap) {
            if (pair.second > threshold) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
