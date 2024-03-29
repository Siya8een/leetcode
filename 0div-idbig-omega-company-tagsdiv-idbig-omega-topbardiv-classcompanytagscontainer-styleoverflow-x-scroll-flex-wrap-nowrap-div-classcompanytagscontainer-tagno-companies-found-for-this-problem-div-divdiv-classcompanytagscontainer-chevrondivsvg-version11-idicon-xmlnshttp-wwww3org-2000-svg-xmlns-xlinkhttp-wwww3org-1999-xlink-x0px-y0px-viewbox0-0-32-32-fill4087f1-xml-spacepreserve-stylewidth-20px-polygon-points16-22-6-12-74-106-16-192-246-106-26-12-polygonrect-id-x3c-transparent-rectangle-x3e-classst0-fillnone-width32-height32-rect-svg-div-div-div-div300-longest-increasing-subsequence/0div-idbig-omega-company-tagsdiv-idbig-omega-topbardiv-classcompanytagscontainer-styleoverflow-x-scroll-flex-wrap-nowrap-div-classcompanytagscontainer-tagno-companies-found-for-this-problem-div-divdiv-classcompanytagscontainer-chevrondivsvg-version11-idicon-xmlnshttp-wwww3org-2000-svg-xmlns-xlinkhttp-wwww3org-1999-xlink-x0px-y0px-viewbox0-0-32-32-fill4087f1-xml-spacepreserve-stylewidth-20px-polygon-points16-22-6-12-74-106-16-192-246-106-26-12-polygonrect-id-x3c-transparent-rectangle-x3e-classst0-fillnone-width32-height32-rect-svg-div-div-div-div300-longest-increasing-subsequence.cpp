#include <vector>
#include <algorithm>

class Solution {
public:
    // recurrence ;
    // memoisation ;
    // tabulation ;
    // space optimisation ;
    // tabukation by tracking prev index element can be taken or not
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.empty()) return 0;

//         int n = nums.size();
//         vector<int> dp(n, 1);

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
    
    
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>........
    
    
//     int solve(int index, int prev, std::vector<int>& nums, std::vector<std::vector<int>>& memo) {
//         if (index == nums.size() ) {
//             return 0;
//         }

//         if (memo[index][prev+1] != -1) {
//             return memo[index][prev+1];
//         }

//         int take = 0, notTake = 0;

//         // Take the current element if it is greater than the previous element
//         if (prev == -1 || (index < nums.size() && nums[index] > nums[prev])) {
//             take = 1 + solve(index + 1, index, nums, memo);
//         }

//         // Skip the current element
//         notTake = solve(index + 1, prev, nums, memo);

//         memo[index][prev+1] = std::max(take, notTake);
//         return memo[index][prev+1];
//     }

    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector < int > next(n+1,0) , cur ( n+1 , 0);
        for ( int index =  n-1 ; index >=0 ;index--){
            for ( int prev_ind  =index-1 ; prev_ind >= -1 ; prev_ind--){
                int len = 0 +  next[prev_ind + 1];
                if ( prev_ind == -1 || nums[index ]> nums[prev_ind]){
                    len = max ( len , 1+ next[index+1]);
                }
                 cur[prev_ind + 1]= len ;
            }
            next = cur;
        }
         return next[0];
    }
    
};
