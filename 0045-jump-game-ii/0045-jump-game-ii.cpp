class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0; // number of jumps taken so far
        int farthest = 0; // farthest index that can be reached with the current number of jumps
        int end = 0; // end of the current jump
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) { // need to take a jump
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};