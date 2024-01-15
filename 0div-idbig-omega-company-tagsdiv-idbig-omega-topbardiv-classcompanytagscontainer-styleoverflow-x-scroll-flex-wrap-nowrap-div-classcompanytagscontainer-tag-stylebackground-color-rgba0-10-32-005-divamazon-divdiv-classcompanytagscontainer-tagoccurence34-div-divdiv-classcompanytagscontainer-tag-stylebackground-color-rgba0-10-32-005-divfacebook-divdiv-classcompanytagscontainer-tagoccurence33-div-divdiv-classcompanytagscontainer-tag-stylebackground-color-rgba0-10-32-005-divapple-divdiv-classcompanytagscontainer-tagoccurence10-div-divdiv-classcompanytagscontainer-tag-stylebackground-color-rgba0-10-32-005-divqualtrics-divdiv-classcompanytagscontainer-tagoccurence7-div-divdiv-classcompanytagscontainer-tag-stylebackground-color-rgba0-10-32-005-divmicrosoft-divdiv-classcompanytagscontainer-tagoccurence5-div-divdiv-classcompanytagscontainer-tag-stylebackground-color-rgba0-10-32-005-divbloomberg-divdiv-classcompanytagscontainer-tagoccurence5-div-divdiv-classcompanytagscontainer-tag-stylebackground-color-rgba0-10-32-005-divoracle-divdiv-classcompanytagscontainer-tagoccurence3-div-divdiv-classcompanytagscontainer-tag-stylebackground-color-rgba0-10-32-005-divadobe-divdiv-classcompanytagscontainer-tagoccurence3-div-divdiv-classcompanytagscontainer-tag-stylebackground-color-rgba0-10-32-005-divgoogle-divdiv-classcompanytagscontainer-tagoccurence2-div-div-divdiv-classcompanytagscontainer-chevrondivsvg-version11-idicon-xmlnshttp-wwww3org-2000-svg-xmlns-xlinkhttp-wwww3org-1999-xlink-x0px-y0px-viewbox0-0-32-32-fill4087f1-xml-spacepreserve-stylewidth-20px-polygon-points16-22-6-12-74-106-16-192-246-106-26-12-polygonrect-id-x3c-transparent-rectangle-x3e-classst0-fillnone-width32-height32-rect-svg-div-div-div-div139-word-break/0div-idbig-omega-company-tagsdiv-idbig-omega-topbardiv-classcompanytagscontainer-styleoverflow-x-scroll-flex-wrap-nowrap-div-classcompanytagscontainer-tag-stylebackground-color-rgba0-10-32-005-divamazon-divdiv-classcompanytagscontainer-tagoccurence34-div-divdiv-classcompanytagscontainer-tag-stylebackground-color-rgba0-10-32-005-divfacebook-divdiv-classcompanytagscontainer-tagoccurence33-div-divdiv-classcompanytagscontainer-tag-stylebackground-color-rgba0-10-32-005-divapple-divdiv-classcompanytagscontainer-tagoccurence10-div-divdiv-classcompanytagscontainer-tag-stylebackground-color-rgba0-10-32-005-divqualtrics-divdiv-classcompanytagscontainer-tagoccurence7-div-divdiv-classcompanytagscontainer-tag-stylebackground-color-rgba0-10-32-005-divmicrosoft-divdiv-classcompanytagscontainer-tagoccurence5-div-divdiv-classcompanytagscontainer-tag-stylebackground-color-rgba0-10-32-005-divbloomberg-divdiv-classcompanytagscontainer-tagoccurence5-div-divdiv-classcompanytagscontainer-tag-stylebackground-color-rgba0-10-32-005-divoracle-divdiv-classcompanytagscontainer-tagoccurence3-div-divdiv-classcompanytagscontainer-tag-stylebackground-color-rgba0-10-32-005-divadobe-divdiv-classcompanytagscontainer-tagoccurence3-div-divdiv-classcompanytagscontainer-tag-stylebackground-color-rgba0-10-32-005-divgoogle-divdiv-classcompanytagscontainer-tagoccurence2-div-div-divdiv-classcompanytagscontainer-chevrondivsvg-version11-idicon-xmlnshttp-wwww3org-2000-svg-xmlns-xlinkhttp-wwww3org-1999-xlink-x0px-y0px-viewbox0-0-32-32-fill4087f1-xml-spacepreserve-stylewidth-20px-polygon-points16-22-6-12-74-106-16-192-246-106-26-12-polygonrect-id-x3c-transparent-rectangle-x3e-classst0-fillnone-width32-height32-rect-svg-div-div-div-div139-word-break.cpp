class Solution {
public:
    
    bool solve(int index, vector<int>& opt, string s, unordered_set<string>& dictWord) {
        if (index >= s.length()) {
            return true;
        }
        if (dictWord.find(s) != dictWord.end()) {
            return true;
        }
        if (opt[index] != -1) {
            return opt[index];
        }
        for (int l = 1; index + l <= s.length(); l++) {
            string temp = s.substr(index, l);
            if (dictWord.find(temp) != dictWord.end() && solve(index + l, opt, s, dictWord)) {
                return opt[index] = true;
            }
        }
        return opt[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictWord;
        vector<int> opt(301, -1);
        for (string& word : wordDict) {
            dictWord.insert(word);
        }
        return solve(0, opt, s, dictWord);
    }
};
