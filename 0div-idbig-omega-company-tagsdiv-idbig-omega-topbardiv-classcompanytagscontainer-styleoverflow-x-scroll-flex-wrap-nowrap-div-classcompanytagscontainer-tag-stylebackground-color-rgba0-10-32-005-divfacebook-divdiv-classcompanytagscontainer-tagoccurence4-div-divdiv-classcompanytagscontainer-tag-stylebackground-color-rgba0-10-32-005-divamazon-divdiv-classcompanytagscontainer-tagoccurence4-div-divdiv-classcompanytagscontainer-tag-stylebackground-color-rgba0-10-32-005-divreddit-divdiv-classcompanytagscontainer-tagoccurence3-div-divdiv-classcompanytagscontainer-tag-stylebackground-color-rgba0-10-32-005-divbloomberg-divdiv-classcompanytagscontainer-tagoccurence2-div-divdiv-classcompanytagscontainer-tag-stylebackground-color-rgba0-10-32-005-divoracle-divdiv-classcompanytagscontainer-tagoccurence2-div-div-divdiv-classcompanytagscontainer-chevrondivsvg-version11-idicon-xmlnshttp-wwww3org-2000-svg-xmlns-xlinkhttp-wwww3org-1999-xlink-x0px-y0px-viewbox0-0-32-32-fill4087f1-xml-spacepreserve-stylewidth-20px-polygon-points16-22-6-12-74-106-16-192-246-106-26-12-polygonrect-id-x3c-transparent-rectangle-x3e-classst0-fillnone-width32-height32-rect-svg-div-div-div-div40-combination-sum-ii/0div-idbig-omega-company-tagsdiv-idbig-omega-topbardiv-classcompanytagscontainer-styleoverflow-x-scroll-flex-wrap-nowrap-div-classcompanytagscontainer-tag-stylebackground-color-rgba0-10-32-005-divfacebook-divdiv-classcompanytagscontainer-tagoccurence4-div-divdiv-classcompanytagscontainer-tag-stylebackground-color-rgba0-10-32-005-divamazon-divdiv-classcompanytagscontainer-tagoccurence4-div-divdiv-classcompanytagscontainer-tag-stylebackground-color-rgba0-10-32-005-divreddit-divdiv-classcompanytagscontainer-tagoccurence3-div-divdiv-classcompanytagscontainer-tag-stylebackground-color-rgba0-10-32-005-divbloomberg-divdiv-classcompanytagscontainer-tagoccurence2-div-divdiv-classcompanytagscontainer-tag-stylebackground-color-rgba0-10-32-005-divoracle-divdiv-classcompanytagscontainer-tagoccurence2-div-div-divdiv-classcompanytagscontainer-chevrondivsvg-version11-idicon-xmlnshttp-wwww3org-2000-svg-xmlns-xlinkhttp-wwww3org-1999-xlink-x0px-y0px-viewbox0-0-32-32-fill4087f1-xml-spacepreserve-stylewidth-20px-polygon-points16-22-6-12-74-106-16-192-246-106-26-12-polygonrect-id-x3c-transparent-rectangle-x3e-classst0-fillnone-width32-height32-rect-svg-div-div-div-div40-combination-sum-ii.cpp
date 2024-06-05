#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void combinationSum2Recursion(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (index >= candidates.size() || target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Include the candidate
            ds.push_back(candidates[i]);
            combinationSum2Recursion(i + 1, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combinationSum2Recursion(0, candidates, target, ans, ds);
        return ans;
    }
};
