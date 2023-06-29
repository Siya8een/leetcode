class Solution {
public:
    int tribonacci(int n) {
      //T0 = 0, T1 = 1, T2 = 1
        
        if ( n==0){
            return 0;
        }
        if ( n==1){
            return 1;
            
        }
        if ( n==2){
            return 1;
        }
        // recursion caused tle
        // int sum = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        //int sum=0;
        vector <int> dp(n+2);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int i=3;
        while ( i<=n){
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
            i++;
        }
        return dp[n];
    }
};