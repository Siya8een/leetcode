class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& a, int start, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(a);
            return;
        }
        if (k == 0 || n <= 0) {
            return;
        }

        for (int i = start; i <= 9; ++i) {
            a.push_back(i);
            solve(ans, a, i + 1, k - 1, n - i);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(ans, a, 1, k, n);
        return ans;
    }
};
