class Solution {
public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Number of even positions
        long long oddCount = n / 2;         // Number of odd positions

        // Calculate (power(5, evenCount) * power(4, oddCount)) % (10^9 + 7)
        long long result = power(5, evenCount) % 1000000007;
        result = (result * power(4, oddCount)) % 1000000007;

        return result;
    }

private:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2) % 1000000007;
        long long result = (half * half) % 1000000007;

        if (exp % 2 == 1)
            result = (result * base) % 1000000007;

        return result;
    }
};
