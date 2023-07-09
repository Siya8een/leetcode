class Solution {
public:
     vector<vector<int>> ans;
    
    void solve(int index, vector<int>& nums, vector<int>& output) {
     
    if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        // Exclude the current element
        solve(index + 1, nums, output);
        
        // Include the current element
        output.push_back(nums[index]);
        solve(index + 1, nums, output);
        
        // Backtrack
        output.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        int index = 0;
        
        solve(index, nums, output);
        
        return ans;
   // vector<vector<int>> subsets(vector<int>& nums) {
        
    }
};