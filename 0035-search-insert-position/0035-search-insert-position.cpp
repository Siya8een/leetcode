   class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // subtract 1 to avoid accessing out-of-bounds element
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // use this formula to avoid integer overflow
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // target not found, return the index where it would be inserted
        return left;
    }
};
   
    