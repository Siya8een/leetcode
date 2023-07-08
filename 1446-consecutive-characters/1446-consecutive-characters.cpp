class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int maxCount = 1; // Updated variable name from count1 to maxCount

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1; // Reset count when streak ends
            }
            
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
