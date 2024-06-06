class Solution {
public:
    int solve ( int sum, int n ,vector<int>& nums,  vector <vector < int >>& dp){
       if ( sum == 0 ){
            return 1;
        }
        if (  sum <0 ||n < 0){
            return 0;
        }
        if( dp[sum][n]!= -1){
            return dp[sum][n];
         }
        //take 
        int take =solve ( sum-nums[n], n-1, nums, dp);
        // not take
         bool not_take =solve ( sum, n-1, nums, dp);
      dp[sum][n]= take || not_take;
        return dp[sum][n];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for( int i =0; i < nums.size();i++){
            sum = sum + nums[i];
        }
         if (sum % 2 != 0) {
            return false;
        }
        vector <vector < int >> dp(sum/2 +1, vector < int>(nums.size(),-1));
        return solve ( sum/2 ,nums.size()-1, nums, dp)== 1;
        
    }
};