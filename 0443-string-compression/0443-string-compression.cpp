#include <vector>
#include <unordered_map>

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) {
            return 1;
        }

        int writeIdx = 0;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                count++;
            } else {
                chars[writeIdx++] = chars[i - 1];
                if (count > 1) {
                    string count_str = to_string(count);
                    for (char c : count_str) {
                        chars[writeIdx++] = c;
                    }
                }
                count = 1;
            }
        }

        // Handle the last character sequence
        chars[writeIdx++] = chars.back();
        if (count > 1) {
            string count_str = to_string(count);
            for (char c : count_str) {
                chars[writeIdx++] = c;
            }
        }

        chars.resize(writeIdx);
        return writeIdx;
    }
};
