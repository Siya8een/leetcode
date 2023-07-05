class Solution {
public:
      vector <vector <int>>ans={};
     vector<vector<int>> solve(vector<int>& nums, int i, vector <int> level) {
       
        
         if( i>= nums.size()){
              ans .push_back ( level );
             return ans;
         }
         
        
         // exclude 
          solve ( nums,i+1, level);
         
         // include 
          level.push_back( nums[i]);
          solve ( nums,i+1, level);
         
         
         
         return ans;
     }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i =0;
         vector <int> level={};
        solve ( nums,i, level);
        return ans;
    }
};