class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1; // Divisor can't be 0
        int end = *max_element(nums.begin(), nums.end());
        int d = 0;

        while (start <= end) {
            int mid = (start + end) / 2;
            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum += ceil(static_cast<double>(nums[i]) / mid);
            }

            if (sum <= threshold) {
                d = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return d;
    }
};
