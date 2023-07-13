class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mpp;
        char ans = '\0'; // Initialize ans with a null character

        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
            if (mpp[s[i]] == 2) {
                ans = s[i];
                break;  // Exit the loop once a repeated character is found
            }
        }

        return ans;
    }
};
