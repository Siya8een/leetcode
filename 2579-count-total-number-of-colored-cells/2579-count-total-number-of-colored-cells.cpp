class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) {
            return 1;
        }
        
        long long m = 2LL * n * n - 2LL * n + 1LL;
        
        return m;
    }
};
