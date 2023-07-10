#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> window;
        long long sum = 0;
        int left = 0;
        long long maxSum = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while (window.count(nums[right]) > 0) {
                window.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            
            window.insert(nums[right]);
            sum += nums[right];
            
            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
                window.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }
        
        return maxSum;
    }
};
