class Solution {
public:
    int climbStairs(int n) {
        vector <int > dp ( n+1);
         if ( n==1)
         {
             return 1;
         } 
        if ( n==2)
         {
             return 2;
         } int prev1=1;
       int  prev2=2;
        int x;
        for ( int i= 3;i <= n ;i++){
      x   = prev1+ prev2;
           prev1=prev2;
            prev2 = x;
            
            
        }
         return x;
    }
};