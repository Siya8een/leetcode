#include <vector>
#include <algorithm>

class Solution {
public:
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
        vector < vector < int >> dp( n+1 , vector < int > ( n+1 , 0));
        for ( int index =  n-1 ; index >=0 ;index--){
            for ( int prev_ind  =index-1 ; prev_ind >= -1 ; prev_ind--){
                int len = 0 +  dp [index+1][prev_ind + 1];
                if ( prev_ind == -1 || nums[index ]> nums[prev_ind]){
                    len = max ( len , 1+ dp[index+1][index+1]);
                }
                 dp [index ][prev_ind + 1]= len ;
            }
        }
         return dp[0][0];
    }
    
};
