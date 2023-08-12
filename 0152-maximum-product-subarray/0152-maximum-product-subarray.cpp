class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // Empty array has a product of 0
        }
        
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if (num < 0) {
                swap(maxProduct, minProduct); // Swap max and min products for negative numbers
            }
            
            maxProduct = max(num, maxProduct * num);
            minProduct = min(num, minProduct * num);
            
            result = max(result, maxProduct);
        }
        
        return result;
    }
};
