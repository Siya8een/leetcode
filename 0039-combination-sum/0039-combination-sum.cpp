#include <vector>

class Solution {
public:
    void solve(std::vector<int>& a, std::vector<std::vector<int>>& ans, int i, std::vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // Take the current candidate
        if (target >= candidates[i]) {
            a.push_back(candidates[i]);
            solve(a, ans, i, candidates, target - candidates[i]); // Not incrementing i allows multiple uses of the same element
            a.pop_back();
        }

        // Don't take the current candidate
        solve(a, ans, i + 1, candidates, target);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> a;
        std::vector<std::vector<int>> ans;
        solve(a, ans, 0, candidates, target);
        return ans;
    }
};
