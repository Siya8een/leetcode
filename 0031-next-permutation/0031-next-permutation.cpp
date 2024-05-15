class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find dip
        int index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            // If no dip found, reverse the entire sequence
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find just larger element to swap with
        int justLarger = nums.size() - 1;
        while (justLarger > index && nums[justLarger] <= nums[index]) {
            justLarger--;
        }
        swap(nums[index], nums[justLarger]);
        
        // Reverse the remaining part to ensure smallest next permutation
        reverse(nums.begin() + index + 1, nums.end());
    }
};
