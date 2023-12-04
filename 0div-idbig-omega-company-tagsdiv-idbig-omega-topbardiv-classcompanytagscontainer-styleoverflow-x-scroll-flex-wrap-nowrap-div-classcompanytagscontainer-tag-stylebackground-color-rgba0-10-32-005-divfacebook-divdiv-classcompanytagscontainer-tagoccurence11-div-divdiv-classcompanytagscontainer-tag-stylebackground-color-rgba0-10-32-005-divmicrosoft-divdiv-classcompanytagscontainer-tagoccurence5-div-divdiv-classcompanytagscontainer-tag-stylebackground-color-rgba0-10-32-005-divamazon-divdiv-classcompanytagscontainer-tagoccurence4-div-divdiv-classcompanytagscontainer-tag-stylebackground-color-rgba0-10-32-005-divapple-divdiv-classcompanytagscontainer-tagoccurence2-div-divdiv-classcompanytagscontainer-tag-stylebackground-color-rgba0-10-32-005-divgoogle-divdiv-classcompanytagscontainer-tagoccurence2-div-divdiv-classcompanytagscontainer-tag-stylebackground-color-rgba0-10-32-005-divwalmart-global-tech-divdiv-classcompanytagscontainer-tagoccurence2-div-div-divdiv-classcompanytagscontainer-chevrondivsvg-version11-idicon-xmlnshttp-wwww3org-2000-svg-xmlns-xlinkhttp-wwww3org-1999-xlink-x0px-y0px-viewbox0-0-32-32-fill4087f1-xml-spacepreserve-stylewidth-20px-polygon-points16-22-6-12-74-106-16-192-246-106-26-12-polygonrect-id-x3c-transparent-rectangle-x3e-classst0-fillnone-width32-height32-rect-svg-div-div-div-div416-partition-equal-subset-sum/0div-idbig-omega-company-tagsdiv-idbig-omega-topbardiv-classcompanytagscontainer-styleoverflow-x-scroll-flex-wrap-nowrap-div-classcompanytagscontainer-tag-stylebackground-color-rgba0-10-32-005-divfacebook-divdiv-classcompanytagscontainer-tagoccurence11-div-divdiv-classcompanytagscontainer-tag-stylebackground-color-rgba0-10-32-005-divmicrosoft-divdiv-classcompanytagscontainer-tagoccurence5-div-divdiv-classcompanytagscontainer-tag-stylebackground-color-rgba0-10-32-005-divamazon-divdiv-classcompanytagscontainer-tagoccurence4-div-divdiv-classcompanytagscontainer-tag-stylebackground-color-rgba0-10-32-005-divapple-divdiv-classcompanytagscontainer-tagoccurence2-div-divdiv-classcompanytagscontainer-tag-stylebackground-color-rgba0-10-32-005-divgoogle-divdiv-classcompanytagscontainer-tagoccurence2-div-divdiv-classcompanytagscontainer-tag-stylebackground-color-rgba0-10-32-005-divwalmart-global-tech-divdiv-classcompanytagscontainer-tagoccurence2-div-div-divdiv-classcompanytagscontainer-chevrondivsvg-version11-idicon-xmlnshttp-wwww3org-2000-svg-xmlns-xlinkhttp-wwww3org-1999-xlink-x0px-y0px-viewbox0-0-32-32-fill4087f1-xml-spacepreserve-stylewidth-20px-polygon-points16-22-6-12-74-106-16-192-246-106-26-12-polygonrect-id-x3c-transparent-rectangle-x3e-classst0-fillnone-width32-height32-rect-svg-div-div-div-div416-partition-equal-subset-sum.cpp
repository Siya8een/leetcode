class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum =0;
         for ( int i=0; i < nums.size();i++){
             sum = sum + nums[i];
         }
        if ( sum%2 !=0){
            return false;
        }
        
        int s = sum / 2;
        int n = nums.size();
        // now our target = s;
      //  vector < vector <bool>> dp ( n, vector <bool>( s+1,0));
        
//         for ( int i =0 ; i< n;i++){
//             dp[i][0]= true;
//         }
        
    //    dp[0][nums[0]]= true;
        vector <bool> prev( s+1, 0);
        vector <bool> curr(s+1, 0);
        prev[0]=true;
        curr[0]= true;
        

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= s; target++) {
            bool nottaken = prev[target];
            bool taken = false;
            if (nums[i] <= target) {
                taken = prev[target - nums[i]];
            }
          curr[target] = nottaken || taken;
        }
        prev = curr;
    }

    return prev[s];
             
    }
};