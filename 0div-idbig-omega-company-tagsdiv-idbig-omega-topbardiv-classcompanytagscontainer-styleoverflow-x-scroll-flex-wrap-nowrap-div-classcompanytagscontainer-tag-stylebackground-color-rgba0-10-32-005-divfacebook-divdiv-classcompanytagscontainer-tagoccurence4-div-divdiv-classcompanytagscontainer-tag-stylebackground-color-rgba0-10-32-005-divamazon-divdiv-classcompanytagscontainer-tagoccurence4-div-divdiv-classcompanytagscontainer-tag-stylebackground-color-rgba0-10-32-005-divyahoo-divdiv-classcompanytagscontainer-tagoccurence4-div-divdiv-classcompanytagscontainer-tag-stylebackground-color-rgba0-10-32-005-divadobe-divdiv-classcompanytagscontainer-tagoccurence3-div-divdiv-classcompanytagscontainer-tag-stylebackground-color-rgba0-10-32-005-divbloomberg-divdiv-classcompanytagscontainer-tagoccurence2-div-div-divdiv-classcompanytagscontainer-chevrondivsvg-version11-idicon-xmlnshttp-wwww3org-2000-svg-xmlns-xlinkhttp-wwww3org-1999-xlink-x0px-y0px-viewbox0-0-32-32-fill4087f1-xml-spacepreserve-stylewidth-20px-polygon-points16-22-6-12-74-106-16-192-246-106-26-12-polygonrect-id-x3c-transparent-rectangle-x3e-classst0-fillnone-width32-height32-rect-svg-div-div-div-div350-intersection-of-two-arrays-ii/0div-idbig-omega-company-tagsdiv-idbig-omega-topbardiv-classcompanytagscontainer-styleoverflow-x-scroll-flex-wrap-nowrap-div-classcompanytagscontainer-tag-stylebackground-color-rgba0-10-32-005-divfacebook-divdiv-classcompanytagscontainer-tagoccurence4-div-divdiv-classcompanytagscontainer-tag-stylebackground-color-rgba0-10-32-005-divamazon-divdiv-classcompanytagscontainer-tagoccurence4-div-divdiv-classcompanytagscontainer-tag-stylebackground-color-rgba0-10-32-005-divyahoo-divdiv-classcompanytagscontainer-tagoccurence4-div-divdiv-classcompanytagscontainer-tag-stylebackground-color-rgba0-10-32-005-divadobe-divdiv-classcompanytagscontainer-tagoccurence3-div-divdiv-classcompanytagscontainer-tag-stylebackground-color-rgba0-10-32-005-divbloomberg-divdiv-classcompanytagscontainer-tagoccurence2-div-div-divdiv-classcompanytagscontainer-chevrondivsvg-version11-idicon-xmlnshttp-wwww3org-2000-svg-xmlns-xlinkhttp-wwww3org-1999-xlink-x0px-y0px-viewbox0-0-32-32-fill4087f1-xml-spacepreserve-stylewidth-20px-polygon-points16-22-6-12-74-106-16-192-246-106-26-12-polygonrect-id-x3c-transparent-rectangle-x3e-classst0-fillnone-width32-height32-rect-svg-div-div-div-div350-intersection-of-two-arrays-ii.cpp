class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        // Count occurrences in nums1
        for (int num : nums1) {
            mpp[num]++;
        }
        
        // Find common elements in nums2
        for (int num : nums2) {
            if (mpp.find(num) != mpp.end() && mpp[num] > 0) {
                ans.push_back(num);
                mpp[num]--;
            }
        }
        
        return ans;
    }
};
