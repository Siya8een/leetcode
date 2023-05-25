class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // Number of even positions
        long long odd = n / 2;         // Number of odd positions

       
        long long result = p(5, even) % 1000000007;
        result = (result * p(4, odd)) % 1000000007;

        return result;
    }

private:
    long long p(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = p(base, exp / 2) % 1000000007;
        long long result = (half * half) % 1000000007;

        if (exp % 2 == 1)
            result = (result * base) % 1000000007;

        return result;
    }
};
