class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> char1(word1.begin(), word1.end());
        vector<char> char2(word2.begin(), word2.end());
        string merged;
        
        int n = char1.size();
        int m = char2.size();
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            merged += char1[i++];
            merged += char2[j++];
        }
        
        while (i < n) {
            merged += char1[i++];
        }
        
        while (j < m) {
            merged += char2[j++];
        }
        
        return merged;
    }
};
