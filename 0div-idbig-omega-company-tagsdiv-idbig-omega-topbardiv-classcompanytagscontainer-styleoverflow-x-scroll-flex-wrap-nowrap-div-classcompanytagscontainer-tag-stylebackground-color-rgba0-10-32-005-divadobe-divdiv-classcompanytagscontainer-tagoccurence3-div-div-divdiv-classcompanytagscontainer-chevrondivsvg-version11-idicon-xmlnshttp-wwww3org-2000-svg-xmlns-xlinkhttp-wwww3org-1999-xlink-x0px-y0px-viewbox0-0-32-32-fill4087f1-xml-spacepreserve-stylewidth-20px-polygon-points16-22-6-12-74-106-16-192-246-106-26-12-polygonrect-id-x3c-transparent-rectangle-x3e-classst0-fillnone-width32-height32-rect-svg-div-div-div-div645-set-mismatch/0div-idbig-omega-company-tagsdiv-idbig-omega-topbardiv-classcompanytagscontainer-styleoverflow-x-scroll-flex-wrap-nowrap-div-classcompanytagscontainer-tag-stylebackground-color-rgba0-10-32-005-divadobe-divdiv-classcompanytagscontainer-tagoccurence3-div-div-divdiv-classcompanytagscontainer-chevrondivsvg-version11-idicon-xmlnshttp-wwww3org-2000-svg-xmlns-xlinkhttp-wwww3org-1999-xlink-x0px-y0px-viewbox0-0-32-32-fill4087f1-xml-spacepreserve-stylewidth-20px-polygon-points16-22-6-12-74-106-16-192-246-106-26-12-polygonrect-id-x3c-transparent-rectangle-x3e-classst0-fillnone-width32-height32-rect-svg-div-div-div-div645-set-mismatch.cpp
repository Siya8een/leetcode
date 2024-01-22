#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        unordered_map<int, int> mpp;

        for (int num : nums) {
            mpp[num]++;
            if (mpp[num] == 2) {
                ans[0] = num; // Found the duplicate number
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (mpp.find(i) == mpp.end()) {
                ans[1] = i; // i is missing
                break;
            }
        }

        return ans;
    }
};
