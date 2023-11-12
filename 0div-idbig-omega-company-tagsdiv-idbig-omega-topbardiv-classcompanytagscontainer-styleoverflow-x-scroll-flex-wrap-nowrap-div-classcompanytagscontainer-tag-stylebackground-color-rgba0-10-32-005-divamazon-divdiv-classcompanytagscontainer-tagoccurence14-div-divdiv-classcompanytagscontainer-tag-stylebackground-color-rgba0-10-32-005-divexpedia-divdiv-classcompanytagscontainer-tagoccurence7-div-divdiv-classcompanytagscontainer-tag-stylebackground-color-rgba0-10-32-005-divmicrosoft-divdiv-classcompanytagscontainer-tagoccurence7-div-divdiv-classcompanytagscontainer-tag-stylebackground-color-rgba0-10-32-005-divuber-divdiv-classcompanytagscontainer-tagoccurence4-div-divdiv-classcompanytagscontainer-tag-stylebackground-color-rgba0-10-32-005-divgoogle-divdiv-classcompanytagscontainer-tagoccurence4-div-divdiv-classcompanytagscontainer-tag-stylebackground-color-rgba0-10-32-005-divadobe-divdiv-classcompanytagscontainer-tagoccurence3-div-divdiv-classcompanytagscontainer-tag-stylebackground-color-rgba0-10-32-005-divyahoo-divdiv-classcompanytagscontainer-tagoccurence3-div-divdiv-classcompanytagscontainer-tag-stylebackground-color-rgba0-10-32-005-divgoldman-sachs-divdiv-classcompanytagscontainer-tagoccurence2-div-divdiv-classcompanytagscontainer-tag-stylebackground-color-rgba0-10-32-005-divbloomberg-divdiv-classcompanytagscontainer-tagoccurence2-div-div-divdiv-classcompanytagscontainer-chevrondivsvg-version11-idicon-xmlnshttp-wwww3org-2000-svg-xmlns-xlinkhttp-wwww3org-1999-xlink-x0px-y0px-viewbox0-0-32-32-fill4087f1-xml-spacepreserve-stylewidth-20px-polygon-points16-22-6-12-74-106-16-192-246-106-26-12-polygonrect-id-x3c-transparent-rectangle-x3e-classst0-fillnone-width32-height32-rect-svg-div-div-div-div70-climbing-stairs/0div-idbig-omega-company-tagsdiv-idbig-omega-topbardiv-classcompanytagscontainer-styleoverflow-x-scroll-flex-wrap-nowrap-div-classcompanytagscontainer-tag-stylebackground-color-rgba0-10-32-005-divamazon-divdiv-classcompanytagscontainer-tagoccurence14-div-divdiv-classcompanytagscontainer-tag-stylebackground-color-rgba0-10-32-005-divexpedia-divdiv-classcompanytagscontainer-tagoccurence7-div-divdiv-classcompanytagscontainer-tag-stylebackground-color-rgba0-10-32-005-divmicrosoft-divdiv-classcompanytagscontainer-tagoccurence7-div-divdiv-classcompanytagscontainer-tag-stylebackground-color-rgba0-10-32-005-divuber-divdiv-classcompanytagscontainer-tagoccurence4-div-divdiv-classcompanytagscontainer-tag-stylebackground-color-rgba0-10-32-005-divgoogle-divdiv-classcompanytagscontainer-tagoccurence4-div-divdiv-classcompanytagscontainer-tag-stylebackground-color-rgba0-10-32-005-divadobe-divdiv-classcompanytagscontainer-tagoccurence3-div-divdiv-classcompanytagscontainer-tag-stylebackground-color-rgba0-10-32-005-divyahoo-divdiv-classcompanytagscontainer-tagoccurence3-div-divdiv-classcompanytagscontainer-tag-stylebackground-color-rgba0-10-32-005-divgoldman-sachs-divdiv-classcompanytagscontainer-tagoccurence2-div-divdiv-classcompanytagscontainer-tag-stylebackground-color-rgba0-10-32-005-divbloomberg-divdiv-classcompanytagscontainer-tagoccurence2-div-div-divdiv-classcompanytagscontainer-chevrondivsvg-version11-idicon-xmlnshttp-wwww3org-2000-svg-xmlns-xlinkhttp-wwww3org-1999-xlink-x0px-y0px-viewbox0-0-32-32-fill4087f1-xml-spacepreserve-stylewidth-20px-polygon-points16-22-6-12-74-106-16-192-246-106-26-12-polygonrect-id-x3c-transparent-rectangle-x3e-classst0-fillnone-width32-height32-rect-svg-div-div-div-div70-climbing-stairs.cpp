// class Solution {
// public:
    
//     int solve(int n ,  vector<int> dp){
        
        
//         if ( dp[n]!= -1){
//             return dp[n];
//         }
//         dp[n] = solve( n-1,dp) + solve( n-2,dp);
        
//         return dp[n];
//     }
    
//     int climbStairs(int n) {
      
//         vector<int> dp( n+1,-1);
//         dp[1]=1;
//         dp[2]=2;
//        return solve( n,dp);
//     }
// };
class Solution {
public:
    int climbStairs(int n) {
        long long prev1 = 1;
        long long prev2 = 2;

        for (int i = 0; i < n - 1; i++) {
            long long x = prev1;
            prev1 = prev2;
            prev2 = x + prev2;
        }

        return static_cast<int>(prev1);
    }
};

