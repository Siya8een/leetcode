#include <string>
#include <algorithm>

class Solution {
public:
    int minimumLength(std::string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            
            // Move left pointer to the right until it encounters a different character or reaches right pointer
            while (left <= right && s[left] == ch) {
                left++;
            }
            
            // Move right pointer to the left until it encounters a different character or reaches left pointer
            while (right >= left && s[right] == ch) {
                right--;
            }
        }
        
        // If left pointer surpasses right pointer, the remaining string is empty
        if (left > right) {
            return 0;
        } else {
            // Otherwise, return the length of the remaining string
            return right - left + 1;
        }
    }
};
