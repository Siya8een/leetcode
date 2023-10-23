class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false; // Negative numbers and zero cannot be a power of four
        }
        if (n == 1) {
            return true; // 4^0 is 1
        }
        if (n % 4 == 0) {
            return isPowerOfFour(n / 4); // Recursively check if n/4 is a power of four
        }
        return false; // If n is not divisible by 4, it's not a power of four
    }
};
