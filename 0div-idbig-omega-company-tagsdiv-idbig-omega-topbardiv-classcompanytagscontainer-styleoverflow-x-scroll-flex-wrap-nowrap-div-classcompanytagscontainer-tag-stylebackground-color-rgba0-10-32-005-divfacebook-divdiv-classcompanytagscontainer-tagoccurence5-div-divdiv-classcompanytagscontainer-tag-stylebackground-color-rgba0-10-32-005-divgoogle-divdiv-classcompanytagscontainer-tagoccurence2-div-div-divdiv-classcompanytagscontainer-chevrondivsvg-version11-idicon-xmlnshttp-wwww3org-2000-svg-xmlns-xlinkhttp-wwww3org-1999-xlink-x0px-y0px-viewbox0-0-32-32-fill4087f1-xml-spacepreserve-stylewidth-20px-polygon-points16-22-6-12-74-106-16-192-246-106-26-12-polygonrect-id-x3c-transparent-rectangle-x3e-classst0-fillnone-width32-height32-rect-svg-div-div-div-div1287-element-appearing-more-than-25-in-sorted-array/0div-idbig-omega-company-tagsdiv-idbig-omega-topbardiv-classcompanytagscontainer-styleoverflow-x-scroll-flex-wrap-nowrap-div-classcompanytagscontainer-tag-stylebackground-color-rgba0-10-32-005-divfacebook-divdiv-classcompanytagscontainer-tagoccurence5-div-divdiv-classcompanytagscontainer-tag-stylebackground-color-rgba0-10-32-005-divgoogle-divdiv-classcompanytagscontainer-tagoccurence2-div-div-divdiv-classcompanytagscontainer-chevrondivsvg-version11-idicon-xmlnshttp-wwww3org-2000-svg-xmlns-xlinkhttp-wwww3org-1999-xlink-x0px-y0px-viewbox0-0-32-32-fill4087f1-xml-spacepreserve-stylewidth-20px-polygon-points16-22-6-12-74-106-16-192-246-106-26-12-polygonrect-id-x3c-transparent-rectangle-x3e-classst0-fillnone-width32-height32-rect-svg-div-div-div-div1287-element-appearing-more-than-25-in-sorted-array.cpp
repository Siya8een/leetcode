#include <vector>
#include <unordered_map>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        // return the element with the highest frequency
        int n = arr.size();
        std::unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            if (mp[arr[i]] >= (n / 4 + 1)) {
                return arr[i];
            }
        }

        return -1; // If no special integer is found
    }
};
