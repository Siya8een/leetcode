class Solution {
public:
    int sum(int first, int last, vector<int>& nums) {
        int s = 0;
        for (int i = first; i < last; i++) {
            s = s + nums[i];
        }
        return s;
    }
    
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (sum(0, i, nums) == sum(i + 1, n, nums)) {
                return i;
            }
        }
        
        return -1;
    }
};
