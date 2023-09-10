class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& ds, int index, vector<int>& candidates, int target) {
        if (target == 0) {
             
            ans.push_back(ds);
            
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            if (candidates[i] > target) {
                break; // If the candidate is larger than the target, stop considering it
            }
            
            ds.push_back(candidates[i]);
            solve(ans, ds, i + 1, candidates, target - candidates[i]);
          
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates properly
        int index = 0;
        solve(ans, ds, index, candidates, target);
        return ans;
    }
};
