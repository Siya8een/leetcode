class Solution {
public:
    int index(int element, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == element) {
                return i;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        vector<int> original = nums;
        sort(original.begin(), original.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = original[left] + original[right];

            if (sum == target) {
                int idx1 = index(original[left], nums);
                int idx2 = index(original[right], nums);
                
                // Avoid using the same index twice
                if (idx1 == idx2) {
                    idx2 = index(original[right], nums, idx1);
                }

                ans.push_back(idx1);
                ans.push_back(idx2);
                return ans;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
    
    int index(int element, vector<int>& nums, int skipIndex) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == element && i != skipIndex) {
                return i;
            }
        }
        return -1;
    }
};
