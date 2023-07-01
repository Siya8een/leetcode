class Solution {
public:
    
    vector<vector<int>> solve ( vector<int> nums,vector<vector<int>> & ans,vector<int> output, int index){
        
        if ( index >= nums.size()){
            ans.push_back(output);
            return ans;
        }
        
        // exclude call
        solve ( nums, ans , output, index+1);
        
        
        // include call
         int element= nums[index];
         output .push_back( element);
         solve ( nums, ans , output, index+1);
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
         
         vector<vector<int>> ans;
         vector <int> output;
        int index= 0;
        solve ( nums, ans , output, index);
        
        return ans;
    }
};