class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> str1;
        unordered_map<int, int> str2;
        
        for (int i = 0; i < s.length(); i++) {
            str1[s[i]]++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            str2[t[i]]++;  // Fixed: Change 'str2[s[i]]' to 'str2[t[i]]'
        }
        
        int ans = 0;  // Fixed: Initialize 'ans' to 0
        for (auto it : str2) {
            int charCountInS = str1.find(it.first) != str1.end() ? str1[it.first] : 0;
            
            if (it.second > charCountInS) {
                ans += (it.second - charCountInS);
            }
        }
        
        return ans;
    }
};
