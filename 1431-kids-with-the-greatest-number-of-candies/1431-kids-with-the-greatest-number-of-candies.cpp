class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = candies[0];
        for (int i = 1; i < candies.size(); i++) {
            maxCandies = max(maxCandies, candies[i]);
        }
        
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            result[i] = candies[i] + extraCandies >= maxCandies;
        }
        
        return result;
    }
};
