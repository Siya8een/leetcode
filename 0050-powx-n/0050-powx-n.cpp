class Solution {
public:
    double solve(double x, long long n) { // Use long long for 'n'
        if (n == 0) {
            return 1.0; // Any number raised to the power of 0 is 1
        }
        
        double half = solve(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
    
    double myPow(double x, int n) {
        long long exp = n; // Convert to long long
        
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        
        return solve(x, exp);
    }
};
