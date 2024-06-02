#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            if (i + k <= s.length()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
