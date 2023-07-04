class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //nlogn se heap sort
        int n= nums.size();
        sort ( nums.begin(),nums.end());
        return nums[n-k];
    }
};