class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n; // No duplicates or at most 2 elements, no changes needed
        }
        
        int count = 2; // Keep track of the count of unique elements
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[count - 2]) {
                nums[count] = nums[i]; // Update the array with unique elements
                count++;
            }
        }
        
        return count;
    }
};
