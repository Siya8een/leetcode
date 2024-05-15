class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        
        while (mid <= end) { // Use <= instead of < to ensure all elements are processed
            if (nums[mid] == 0) {
                swap(nums[mid], nums[start]);
                start++;
                mid++; // Increment mid as we're sure that nums[start] is either 0 or 1
            } else if (nums[mid] == 1) {
                mid++; // No need to swap as nums[mid] is already 1
            } else { // nums[mid] == 2
                swap(nums[mid], nums[end]);
                end--;
                // We don't increment mid here because after swapping, nums[mid] could be 0 or 1
            }
        }
    }
};
