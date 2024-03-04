#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        int score = 0;
        int max_score = 0;
        int i = 0, j = tokens.size() - 1;
        
        std::sort(tokens.begin(), tokens.end());
        
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
                max_score = std::max(max_score, score);
            } else if (score > 0) {
                power += tokens[j];
                score--;
                j--;
            } else {
                break;
            }
        }
        
        return max_score;
    }
};
