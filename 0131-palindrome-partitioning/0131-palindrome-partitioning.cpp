class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> r;
        int index = 0;
        solve(s, ans, r, index);
        return ans;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string>& r, int index) {
        if (index == s.length()) {
            ans.push_back(r);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                r.push_back(s.substr(index, i - index + 1));
                solve(s, ans, r, i + 1);
                r.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
