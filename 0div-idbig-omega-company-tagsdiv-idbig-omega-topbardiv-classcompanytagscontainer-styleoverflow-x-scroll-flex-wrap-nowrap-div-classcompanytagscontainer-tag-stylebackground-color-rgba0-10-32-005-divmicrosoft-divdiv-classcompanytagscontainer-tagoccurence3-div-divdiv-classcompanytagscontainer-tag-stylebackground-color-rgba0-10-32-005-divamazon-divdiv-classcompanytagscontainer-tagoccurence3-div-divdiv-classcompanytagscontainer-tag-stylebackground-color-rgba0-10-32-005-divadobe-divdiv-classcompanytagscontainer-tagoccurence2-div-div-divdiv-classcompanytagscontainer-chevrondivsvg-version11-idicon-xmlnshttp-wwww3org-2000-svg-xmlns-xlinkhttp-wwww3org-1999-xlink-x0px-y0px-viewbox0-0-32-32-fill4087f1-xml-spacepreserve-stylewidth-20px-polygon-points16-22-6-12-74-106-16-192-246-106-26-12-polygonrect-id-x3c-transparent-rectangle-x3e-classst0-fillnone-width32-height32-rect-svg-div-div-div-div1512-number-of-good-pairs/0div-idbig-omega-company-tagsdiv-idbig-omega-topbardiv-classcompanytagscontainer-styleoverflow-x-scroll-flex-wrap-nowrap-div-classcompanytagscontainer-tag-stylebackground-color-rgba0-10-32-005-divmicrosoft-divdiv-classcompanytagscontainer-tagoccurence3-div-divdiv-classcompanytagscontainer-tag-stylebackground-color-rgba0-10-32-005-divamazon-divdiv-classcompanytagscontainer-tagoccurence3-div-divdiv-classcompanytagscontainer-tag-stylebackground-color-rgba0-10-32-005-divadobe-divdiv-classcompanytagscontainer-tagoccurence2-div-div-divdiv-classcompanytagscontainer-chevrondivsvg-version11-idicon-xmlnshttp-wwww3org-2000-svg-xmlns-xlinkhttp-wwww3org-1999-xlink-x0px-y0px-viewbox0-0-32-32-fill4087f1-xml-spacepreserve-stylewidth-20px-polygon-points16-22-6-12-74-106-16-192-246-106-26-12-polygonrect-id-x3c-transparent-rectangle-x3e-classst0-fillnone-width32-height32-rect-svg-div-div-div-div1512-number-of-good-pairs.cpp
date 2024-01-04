class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int, int> map;
        int ans = 0;

        for(auto i : nums){
          ans += map[i];
          map[i]++;
        }
        return ans;
    }
};