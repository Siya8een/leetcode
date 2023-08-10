class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[left] < nums[mid]) { // left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // search in left half
                } else {
                    left = mid + 1; // search in right half
                }
            } else if (nums[left] > nums[mid]) { // right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // search in right half
                } else {
                    right = mid - 1; // search in left half
                }
            } else { // nums[left] == nums[mid]
                left++; // skip duplicates
            }
        }
        
        // not present
        return false;
    }
};
