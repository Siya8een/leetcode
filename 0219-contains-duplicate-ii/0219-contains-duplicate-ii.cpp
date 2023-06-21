class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> indices;

        for (int i = 0; i < n; i++) {
            if (indices.find(nums[i]) != indices.end() && i - indices[nums[i]] <= k) {
                return true;
            }
            indices[nums[i]] = i;
        }

        return false;
    }
};
