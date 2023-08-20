class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k % n; // Adjust k to be within the range of array size

        std::map<int, int> rotatedMap;

        // Store the elements with their new indices after rotation
        for (int i = 0; i < n; ++i) {
            int newIndex = (i + k) % n;
            rotatedMap[newIndex] = nums[i];
        }

        // Update the original array with rotated values from the map
        for (const auto& entry : rotatedMap) {
            nums[entry.first] = entry.second;
        }
    }
};