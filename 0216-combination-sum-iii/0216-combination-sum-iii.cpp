class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& b, int k, int n,vector<int>& a, int index) {
        if (b.size() == k && accumulate(b.begin(), b.end(), 0) == n) {
            ans.push_back(b);
            return;
        }
        
        for (int i = index; i < a.size(); i++) {
            // If adding a[i] would exceed the target n, skip this value
            if (a[i] + accumulate(b.begin(), b.end(), 0) > n)
                continue;
            
            b.push_back(a[i]);
            solve(ans, b, k,n, a, i + 1);  // Move to the next index to avoid duplicates
            b.pop_back();  // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        for (int i = 1; i <= 9; i++) {
            a.push_back(i);
        }
        vector<int> b;
        int index = 0;
        solve(ans, b, k,n, a, index);
        
        return ans;
    }
};
