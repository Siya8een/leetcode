class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> ans;
       vector <int> neg;
        vector <int> pos;
        for ( int i=0;i< nums.size();i++){
            if ( nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                 neg.push_back(nums[i]);
            }
        }
        int minSize = min(pos.size(), neg.size());

        // Interleave positive and non-positive numbers alternatively
        for (int i = 0; i < minSize; i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        // Add any remaining elements from the longer vector
        for (int i = minSize; i < pos.size(); i++) {
            ans.push_back(pos[i]);
        }

        for (int i = minSize; i < neg.size(); i++) {
            ans.push_back(neg[i]);
        }
        return ans;
    }
};