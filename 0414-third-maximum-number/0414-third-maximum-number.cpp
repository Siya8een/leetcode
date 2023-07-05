class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        if (s.size() < 3) {
            // If the set contains less than 3 distinct elements,
            // return the maximum element
            return *s.rbegin();
        }

        // Return the third maximum element in the set
        auto it = s.rbegin();
        advance(it, 2);
        return *it;
    }
};
