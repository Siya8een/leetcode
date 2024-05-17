class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00000;
        long long a = n ;
        if ( a < 0){
            a = 0 - a;
        }
        double to_muntiplied;
        while ( a > 0){
            if ( a % 2 ==0){
                x= x*x;
                
                a = a/2;
            }
            else if ( a % 2==1){
                a = (a-1)/2;
                ans = ans * x;
                x = x*x;
                 
            }
        }
        if ( n < 0){
            ans = 1/ ans ;
        }
        return ans ;
    }
};