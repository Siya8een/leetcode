class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            cnt = 0;
            
            // Count numbers less than or equal to mid
            for(int n : nums) {
                if(n <= mid)
                    ++cnt;
            }
            
            // Binary search on the left
            if(cnt <= mid)
                low = mid + 1;
            else
            // Binary search on the right
                high = mid - 1;
        }
        
        return low;
    }
};