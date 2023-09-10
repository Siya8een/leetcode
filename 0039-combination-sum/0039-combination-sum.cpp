class Solution {
public:
    void solve(vector<vector<int>>& ans, int index, vector<int>& combo, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(combo);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        // Include the current candidate and make a recursive call
        combo.push_back(candidates[index]);
        solve(ans, index, combo, candidates, target - candidates[index]);

        // Exclude the current candidate and make a recursive call
        combo.pop_back();
        solve(ans, index + 1, combo, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        int index = 0;
        solve(ans, index, combo, candidates, target);
        return ans;
    }
};
