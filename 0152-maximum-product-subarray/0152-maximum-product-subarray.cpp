class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // Return 0 for an empty array
        }
        
        int currentMaxPositive = nums[0]; // Maximum positive product ending at index i
        int currentMinNegative = nums[0]; // Minimum negative product ending at index i
        int globalMax = nums[0];          // Maximum product seen so far
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if (num < 0) {
                // Update currentMaxPositive and currentMinNegative based on the current number
                int temp = currentMaxPositive;
                currentMaxPositive = max(num, currentMinNegative * num);
              currentMinNegative = min(num, temp * num);
            } else {
                // Update currentMaxPositive and currentMinNegative for positive numbers
                currentMaxPositive = max(num, currentMaxPositive * num);
              currentMinNegative = min(num, currentMinNegative * num);
            }
            
            // Update the global maximum product if necessary
            globalMax = max(globalMax, currentMaxPositive);
        }
        
        return globalMax; // Return the maximum product
    }
};
