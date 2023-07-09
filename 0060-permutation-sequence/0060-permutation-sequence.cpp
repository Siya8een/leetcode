class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back('0' + i);
        }
        
        string ans = nums;
        for (int i = 1; i < k; i++) {
            next_permutation(nums.begin(), nums.end());
            ans = nums;
        }
        
        return ans;
    }
};
