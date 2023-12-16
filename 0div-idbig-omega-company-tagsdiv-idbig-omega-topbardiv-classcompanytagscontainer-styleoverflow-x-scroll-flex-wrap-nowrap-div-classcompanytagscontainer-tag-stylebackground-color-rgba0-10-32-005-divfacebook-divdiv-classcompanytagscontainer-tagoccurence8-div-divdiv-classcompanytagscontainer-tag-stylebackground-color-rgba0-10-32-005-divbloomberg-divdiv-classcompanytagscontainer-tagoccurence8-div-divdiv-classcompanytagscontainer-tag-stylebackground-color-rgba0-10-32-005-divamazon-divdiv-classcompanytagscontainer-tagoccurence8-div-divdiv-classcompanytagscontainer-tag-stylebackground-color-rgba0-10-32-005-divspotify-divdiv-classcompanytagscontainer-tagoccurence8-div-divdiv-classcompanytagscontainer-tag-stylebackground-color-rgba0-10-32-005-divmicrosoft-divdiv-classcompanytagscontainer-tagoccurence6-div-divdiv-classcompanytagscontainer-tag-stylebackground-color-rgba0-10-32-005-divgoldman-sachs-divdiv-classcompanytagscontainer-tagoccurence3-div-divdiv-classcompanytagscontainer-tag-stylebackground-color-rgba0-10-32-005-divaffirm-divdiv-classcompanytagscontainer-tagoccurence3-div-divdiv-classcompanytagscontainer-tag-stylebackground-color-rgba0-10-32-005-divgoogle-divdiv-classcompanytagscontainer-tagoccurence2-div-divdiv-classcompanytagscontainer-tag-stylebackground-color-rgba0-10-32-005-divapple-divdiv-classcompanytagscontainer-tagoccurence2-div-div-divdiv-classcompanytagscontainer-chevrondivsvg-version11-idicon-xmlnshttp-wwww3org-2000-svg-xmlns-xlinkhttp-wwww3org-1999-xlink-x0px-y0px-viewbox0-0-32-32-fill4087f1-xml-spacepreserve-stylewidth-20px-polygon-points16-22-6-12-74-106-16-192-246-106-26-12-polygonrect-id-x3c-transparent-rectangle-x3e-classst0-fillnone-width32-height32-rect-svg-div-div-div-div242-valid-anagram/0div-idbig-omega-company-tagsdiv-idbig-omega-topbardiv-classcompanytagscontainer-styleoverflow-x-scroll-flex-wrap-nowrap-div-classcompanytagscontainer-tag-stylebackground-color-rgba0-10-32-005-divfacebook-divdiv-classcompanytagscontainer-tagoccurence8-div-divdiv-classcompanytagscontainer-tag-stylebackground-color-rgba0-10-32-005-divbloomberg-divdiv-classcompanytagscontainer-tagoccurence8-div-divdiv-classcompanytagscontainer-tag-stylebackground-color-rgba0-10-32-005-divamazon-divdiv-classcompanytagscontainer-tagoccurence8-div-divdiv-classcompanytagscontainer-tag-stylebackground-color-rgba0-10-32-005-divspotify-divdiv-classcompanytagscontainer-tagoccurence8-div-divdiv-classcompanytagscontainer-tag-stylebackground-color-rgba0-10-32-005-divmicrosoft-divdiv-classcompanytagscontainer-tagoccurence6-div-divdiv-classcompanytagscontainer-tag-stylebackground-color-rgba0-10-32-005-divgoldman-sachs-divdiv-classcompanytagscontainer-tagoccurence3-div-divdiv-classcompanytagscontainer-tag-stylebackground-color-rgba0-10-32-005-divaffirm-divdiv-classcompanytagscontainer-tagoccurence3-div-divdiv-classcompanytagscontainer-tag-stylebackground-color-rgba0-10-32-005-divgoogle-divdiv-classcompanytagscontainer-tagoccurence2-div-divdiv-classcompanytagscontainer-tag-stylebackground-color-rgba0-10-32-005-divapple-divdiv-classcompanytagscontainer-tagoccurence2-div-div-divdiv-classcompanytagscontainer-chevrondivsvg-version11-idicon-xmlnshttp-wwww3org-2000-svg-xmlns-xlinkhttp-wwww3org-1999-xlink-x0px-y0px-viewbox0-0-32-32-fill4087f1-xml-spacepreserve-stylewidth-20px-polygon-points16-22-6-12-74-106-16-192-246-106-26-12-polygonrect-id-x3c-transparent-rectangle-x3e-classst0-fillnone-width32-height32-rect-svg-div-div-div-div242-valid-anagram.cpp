class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> mpp;
        unordered_map<char, int> mppp;
        
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            mppp[t[i]]++;
        }
        
        // Compare the contents of mpp and mppp
        return mpp == mppp;
    }
};
