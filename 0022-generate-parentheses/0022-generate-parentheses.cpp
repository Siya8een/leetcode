class Solution {
public:
    void solve(int n, vector<string>& ans, string current, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }
        
        if (open > 0) {
            solve(n, ans, current + '(', open - 1, close);
        }
        
        if (close > open) {
            solve(n, ans, current + ')', open, close - 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string current = "";
        
        solve(n, ans, current, open, close);
        
        return ans;
    }
};
