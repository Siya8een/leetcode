class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = (n * (n + 1)) / 2;  // Sum of numbers from 1 to n

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += nums[i];
        }

        return s - ans;
    }
};
