class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> charMap;
        int maxLen = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (charMap.count(s[j])) {
                i = max(i, charMap[s[j]] + 1);
            }
            charMap[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};