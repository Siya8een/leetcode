class Solution {
public:
    
    vector<vector<int>> solve (vector<vector<int>>& ans, int index,  vector<int> nums ){
        
        if (index >= nums .size()){
            ans .push_back ( nums );
             return ans ;
        }
        
        // swap
        
         for ( int i=index;i < nums .size();i++){
             swap ( nums[ index ], nums [i]);
               solve ( ans , index + 1,nums);
              swap ( nums[ index ], nums [i]);
         }
        return ans;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        //vector<int> output;
        int index;
         solve ( ans , index,nums);
         return ans;
    }
};