#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& a, vector<vector<int>>& ans, int i, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // Take the current candidate
        a.push_back(candidates[i]);
        solve(a, ans, i, candidates, target - candidates[i]);
        a.pop_back();

        // Don't take the current candidate
        solve(a, ans, i + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        int index = 0;
        solve(a, ans, index, candidates, target);
        return ans;
    }
};
