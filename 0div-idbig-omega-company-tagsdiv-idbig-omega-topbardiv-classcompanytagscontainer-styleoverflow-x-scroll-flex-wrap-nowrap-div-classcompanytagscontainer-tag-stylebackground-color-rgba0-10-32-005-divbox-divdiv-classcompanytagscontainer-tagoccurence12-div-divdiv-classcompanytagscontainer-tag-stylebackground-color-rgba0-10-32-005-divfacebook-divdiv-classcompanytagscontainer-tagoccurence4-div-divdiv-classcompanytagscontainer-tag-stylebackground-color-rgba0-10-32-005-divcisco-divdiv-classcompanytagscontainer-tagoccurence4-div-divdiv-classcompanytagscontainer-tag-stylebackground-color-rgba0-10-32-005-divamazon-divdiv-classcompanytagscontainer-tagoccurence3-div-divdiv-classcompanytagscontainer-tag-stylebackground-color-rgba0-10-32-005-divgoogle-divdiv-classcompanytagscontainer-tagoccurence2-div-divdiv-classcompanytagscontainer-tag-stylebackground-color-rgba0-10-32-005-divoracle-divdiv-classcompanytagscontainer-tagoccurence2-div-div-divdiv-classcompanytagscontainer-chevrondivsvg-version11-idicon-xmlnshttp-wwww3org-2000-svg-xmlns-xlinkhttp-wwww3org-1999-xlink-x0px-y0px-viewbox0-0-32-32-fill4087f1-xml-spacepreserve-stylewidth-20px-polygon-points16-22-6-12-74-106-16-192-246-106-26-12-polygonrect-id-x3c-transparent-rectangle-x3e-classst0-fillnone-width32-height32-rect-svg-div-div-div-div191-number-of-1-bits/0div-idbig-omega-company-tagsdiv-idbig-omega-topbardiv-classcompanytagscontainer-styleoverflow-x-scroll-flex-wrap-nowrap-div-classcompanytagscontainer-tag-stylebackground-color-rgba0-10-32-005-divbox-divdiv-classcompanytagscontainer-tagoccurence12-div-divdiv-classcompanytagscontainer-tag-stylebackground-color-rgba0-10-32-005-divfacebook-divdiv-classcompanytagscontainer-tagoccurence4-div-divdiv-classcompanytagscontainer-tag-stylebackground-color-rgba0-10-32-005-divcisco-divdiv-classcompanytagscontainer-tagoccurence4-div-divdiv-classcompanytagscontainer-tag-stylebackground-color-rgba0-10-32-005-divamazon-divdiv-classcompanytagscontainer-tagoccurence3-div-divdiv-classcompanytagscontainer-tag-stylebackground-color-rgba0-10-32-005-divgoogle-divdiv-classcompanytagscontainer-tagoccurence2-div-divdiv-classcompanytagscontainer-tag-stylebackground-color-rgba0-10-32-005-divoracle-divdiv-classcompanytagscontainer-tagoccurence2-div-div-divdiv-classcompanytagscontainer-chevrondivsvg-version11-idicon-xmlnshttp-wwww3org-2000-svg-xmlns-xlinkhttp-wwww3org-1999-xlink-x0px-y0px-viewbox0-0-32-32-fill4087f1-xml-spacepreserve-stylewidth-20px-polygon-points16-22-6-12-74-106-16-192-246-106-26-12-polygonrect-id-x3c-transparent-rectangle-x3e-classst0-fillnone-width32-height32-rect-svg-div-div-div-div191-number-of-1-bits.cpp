class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) != 0) {
                count++;
            }
            n >>= 1;  // Corrected the typo here
        }
        return count;
    }
};
