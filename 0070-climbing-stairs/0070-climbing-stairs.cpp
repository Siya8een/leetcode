class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 =1;
        if ( n==0||n==1){
            return prev1;
        }
           int ans=0;
        for ( int i=2;i<= n;i++){
            ans = prev1+prev2;
            prev1= prev2;
            prev2 = ans;
        }
        return ans;
    }
};