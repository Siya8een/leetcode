class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& r, int target, int index) {
        if (target == 0) {
            ans.push_back(r);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates to avoid duplicate combinations
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (target < candidates[i])
                return;  // Optimization: candidates are sorted, so further candidates won't work

            r.push_back(candidates[i]);
            solve(ans, candidates, r, target - candidates[i], i + 1);
            r.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int index = 0;
        vector<vector<int>> ans;
        vector<int> r;
        solve(ans, candidates, r, target, index);
        return ans;
    }
};
