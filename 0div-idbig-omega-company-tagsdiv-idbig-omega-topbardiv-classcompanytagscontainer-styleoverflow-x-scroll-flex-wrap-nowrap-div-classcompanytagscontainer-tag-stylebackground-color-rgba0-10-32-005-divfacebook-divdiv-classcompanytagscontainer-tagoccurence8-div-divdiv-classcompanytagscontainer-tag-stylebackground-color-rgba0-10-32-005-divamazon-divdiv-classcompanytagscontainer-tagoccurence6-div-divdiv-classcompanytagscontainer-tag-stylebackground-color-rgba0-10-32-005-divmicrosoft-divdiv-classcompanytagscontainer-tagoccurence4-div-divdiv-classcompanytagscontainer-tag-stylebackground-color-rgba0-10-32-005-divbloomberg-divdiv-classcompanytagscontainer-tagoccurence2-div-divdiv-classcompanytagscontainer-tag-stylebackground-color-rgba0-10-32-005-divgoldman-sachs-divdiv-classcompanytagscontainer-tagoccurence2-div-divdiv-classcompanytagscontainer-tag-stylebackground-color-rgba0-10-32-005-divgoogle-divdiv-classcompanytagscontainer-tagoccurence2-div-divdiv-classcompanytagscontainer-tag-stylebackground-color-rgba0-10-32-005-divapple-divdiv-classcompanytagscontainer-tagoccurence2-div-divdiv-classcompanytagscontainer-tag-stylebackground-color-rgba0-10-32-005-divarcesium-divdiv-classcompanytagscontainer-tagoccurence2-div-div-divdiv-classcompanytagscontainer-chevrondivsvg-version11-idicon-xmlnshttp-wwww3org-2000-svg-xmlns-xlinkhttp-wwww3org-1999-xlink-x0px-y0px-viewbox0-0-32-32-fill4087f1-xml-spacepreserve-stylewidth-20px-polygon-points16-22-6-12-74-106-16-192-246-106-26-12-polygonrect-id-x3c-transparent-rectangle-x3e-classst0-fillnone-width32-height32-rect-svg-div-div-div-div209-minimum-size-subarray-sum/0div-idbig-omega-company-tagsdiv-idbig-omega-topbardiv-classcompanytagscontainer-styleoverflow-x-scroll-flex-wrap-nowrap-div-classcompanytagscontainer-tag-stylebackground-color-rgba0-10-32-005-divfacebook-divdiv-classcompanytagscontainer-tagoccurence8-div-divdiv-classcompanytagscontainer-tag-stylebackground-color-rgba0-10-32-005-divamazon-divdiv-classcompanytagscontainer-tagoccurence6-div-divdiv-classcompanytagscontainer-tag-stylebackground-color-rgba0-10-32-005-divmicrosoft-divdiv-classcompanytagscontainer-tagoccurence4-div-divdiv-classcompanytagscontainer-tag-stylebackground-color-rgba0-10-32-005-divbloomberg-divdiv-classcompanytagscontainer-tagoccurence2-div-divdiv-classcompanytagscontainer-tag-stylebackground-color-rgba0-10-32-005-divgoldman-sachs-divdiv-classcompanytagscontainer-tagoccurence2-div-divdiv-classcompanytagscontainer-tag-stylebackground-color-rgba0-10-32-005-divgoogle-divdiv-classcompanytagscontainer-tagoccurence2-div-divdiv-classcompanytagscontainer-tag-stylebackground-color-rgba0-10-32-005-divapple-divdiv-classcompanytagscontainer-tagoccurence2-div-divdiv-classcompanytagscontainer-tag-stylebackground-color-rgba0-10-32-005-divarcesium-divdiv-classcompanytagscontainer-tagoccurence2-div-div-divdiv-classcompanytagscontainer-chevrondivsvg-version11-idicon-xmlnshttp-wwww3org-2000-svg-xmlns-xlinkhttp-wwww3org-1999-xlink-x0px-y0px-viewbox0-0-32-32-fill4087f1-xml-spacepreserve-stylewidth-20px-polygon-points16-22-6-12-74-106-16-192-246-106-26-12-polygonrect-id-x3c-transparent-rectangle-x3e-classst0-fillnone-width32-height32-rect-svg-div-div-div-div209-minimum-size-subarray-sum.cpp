class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minAns = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0; // Corrected initialization
        while (j < nums.size()) {
            sum += nums[j];
            
            while (sum >= target) {
                minAns = min(minAns, j - i + 1);
                sum -= nums[i];
                i++;
            }
            
            j++;
        }
        
     if (minAns == INT_MAX) 
         return 0 ;
         
         else{
             return minAns;
         }
    }
};
