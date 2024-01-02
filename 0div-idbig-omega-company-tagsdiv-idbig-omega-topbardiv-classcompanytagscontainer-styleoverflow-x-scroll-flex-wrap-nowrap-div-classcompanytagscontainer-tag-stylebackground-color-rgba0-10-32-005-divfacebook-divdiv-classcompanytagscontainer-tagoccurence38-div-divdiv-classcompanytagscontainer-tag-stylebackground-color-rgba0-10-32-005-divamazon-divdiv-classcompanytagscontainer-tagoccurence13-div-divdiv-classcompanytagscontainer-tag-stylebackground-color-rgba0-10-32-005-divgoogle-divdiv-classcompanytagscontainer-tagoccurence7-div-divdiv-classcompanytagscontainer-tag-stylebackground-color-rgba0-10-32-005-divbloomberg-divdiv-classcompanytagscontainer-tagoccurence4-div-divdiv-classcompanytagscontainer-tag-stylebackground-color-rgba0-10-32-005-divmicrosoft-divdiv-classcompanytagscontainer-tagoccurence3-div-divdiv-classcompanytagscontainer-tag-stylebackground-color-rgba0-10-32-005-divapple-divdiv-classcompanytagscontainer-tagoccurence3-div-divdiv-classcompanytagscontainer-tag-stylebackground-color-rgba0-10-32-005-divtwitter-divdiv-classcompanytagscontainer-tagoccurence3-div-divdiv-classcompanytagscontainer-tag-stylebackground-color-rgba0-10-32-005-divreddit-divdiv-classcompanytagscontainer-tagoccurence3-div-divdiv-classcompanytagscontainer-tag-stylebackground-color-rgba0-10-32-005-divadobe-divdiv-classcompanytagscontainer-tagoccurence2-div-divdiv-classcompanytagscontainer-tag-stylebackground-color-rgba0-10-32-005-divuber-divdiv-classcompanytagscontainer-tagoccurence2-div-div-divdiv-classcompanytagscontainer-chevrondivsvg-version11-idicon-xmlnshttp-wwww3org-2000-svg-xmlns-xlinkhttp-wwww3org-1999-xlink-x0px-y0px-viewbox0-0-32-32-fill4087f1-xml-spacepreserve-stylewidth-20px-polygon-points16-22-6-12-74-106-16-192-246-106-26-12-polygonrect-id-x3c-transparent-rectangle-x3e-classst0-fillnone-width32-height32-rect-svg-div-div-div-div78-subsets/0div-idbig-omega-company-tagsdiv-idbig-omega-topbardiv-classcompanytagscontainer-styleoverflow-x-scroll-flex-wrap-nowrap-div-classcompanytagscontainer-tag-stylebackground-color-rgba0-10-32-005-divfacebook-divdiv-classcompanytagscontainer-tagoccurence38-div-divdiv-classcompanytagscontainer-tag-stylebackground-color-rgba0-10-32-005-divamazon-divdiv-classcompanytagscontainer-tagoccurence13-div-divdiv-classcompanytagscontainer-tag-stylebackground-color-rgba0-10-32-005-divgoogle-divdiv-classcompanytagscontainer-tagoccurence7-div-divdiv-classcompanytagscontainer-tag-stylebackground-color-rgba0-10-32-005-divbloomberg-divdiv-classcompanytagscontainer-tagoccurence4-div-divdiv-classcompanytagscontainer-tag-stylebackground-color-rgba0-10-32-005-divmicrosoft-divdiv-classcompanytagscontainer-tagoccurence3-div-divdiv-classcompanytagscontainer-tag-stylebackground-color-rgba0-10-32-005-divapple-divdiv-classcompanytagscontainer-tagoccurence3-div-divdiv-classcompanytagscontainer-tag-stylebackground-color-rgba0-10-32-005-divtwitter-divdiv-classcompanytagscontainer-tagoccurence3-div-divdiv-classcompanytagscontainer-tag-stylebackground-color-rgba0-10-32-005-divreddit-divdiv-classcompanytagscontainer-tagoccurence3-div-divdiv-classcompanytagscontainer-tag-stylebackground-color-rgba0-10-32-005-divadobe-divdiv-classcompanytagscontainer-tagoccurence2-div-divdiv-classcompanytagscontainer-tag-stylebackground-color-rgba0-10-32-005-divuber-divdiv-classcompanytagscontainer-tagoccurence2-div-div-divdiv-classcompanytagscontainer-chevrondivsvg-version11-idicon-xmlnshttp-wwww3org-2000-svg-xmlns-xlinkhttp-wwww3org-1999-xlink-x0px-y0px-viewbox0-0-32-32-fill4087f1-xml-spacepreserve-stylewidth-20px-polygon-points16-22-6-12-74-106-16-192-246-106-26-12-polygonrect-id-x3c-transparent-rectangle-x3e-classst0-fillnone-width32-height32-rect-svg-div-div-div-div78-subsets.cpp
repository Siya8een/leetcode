class Solution {
public:
    
    void solve (vector<int>& nums,  int i ,vector < vector < int > >& ans, vector < int > & subans){
        if ( i < 0){
             ans.push_back( subans);
            return;
        }
        //include 
       
          solve ( nums, i -1 , ans, subans);
       // subans.pop_back();
        // backtrack
        
        //exclude
            subans.push_back(nums[i]);
          solve ( nums, i -1 , ans, subans);
           subans.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector < int > subans ;
        vector < vector < int > > ans ;
        solve ( nums, nums.size() -1 , ans, subans);
        return ans;
    }
};