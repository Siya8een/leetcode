class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        
        
        int a = m + n - 2;
        int b = n - 1;
        double ans = 1;

        for (int i = 1; i <= b; i++) {
            ans = ans * (a - b + i) / i;
        }

        return (int)ans;
    }
};
