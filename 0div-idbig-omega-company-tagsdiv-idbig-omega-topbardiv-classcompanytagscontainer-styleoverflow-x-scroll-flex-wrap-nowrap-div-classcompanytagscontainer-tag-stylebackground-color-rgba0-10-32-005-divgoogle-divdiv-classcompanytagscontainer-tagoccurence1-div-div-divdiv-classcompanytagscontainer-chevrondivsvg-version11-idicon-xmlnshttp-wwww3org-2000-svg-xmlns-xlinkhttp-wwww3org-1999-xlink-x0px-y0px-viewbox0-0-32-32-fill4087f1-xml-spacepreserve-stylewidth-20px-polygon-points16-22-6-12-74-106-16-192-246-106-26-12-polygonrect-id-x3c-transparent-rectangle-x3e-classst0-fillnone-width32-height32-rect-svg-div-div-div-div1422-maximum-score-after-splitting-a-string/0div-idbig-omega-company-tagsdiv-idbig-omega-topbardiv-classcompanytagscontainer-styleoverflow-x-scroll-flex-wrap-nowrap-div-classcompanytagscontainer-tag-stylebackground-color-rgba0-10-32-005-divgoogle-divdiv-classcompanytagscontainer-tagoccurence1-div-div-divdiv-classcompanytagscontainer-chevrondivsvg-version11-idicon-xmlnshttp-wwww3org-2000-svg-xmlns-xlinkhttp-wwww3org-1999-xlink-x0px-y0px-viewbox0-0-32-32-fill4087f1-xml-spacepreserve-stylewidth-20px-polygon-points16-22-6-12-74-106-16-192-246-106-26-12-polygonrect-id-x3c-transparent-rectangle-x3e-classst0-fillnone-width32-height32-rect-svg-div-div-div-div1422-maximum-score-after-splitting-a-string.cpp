
class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;

        // Count the total number of ones
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        int maxScore = INT_MIN;

        // Iterate through the string (except the last character)
        for (int i = 0; i < s.length() - 1; i++) {
            // Update counts based on the current character
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }

            // Calculate the current score
            int currentScore = zeros + ones;

            // Update the maximum score
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
