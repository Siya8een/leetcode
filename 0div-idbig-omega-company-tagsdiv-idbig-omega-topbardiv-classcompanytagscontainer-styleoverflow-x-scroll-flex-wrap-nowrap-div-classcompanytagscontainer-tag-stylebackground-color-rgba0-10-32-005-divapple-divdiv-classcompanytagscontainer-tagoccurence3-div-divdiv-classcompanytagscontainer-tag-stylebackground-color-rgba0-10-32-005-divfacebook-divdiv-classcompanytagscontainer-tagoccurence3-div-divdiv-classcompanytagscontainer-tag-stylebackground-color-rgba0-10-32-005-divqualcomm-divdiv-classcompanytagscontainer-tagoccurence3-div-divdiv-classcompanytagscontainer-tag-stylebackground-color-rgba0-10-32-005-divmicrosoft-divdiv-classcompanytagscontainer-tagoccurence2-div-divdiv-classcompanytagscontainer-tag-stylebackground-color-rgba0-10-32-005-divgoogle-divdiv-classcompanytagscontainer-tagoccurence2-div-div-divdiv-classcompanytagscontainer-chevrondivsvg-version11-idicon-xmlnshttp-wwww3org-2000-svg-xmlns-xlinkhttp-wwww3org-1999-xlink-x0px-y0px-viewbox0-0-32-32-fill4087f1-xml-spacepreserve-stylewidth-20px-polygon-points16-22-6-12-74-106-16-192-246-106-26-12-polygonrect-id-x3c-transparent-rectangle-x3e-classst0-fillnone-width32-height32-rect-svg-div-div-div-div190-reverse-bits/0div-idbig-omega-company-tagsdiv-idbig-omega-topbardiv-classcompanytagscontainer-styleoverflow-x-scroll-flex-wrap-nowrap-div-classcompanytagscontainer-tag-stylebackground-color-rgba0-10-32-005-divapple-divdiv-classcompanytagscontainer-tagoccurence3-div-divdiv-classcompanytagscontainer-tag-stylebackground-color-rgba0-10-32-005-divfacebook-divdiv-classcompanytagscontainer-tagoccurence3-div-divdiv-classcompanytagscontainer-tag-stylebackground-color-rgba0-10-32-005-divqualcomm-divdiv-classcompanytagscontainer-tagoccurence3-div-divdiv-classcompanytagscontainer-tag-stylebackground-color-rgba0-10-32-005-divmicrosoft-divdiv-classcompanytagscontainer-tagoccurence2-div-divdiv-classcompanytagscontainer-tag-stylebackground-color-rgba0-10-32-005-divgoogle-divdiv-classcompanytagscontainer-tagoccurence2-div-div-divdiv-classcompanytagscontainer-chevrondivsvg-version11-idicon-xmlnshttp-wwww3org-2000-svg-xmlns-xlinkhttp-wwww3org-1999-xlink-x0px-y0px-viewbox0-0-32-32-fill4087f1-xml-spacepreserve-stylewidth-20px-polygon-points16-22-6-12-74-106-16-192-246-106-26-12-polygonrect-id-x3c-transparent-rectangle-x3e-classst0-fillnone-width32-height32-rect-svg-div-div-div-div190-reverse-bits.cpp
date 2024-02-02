#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 31; i >= 0; i--) {
            ans += (n & 1) << i; // Use bitwise left shift instead of pow(2, i)
            n >>= 1;  // Right shift n to get the next bit
        }

        return ans;
    }
};
