class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int j = n - 1;
        int count = 0;

        while (j >= 0 && s[j] == ' ') {
            // Skip trailing spaces
            j--;
        }

        while (j >= 0 && s[j] != ' ') {
            // Count the characters of the last word
            count++;
            j--;
        }

        return count;
    }
};
