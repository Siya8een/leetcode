class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int maxVowel = INT_MIN;
        int vowelNo = 0;

        int i = 0;
        int j = 0;

        while (j < s.length()) {
            if (isVowel(s[j])) {
                vowelNo++;
            }
            if (j - i + 1 == k) {
                maxVowel = max(maxVowel, vowelNo);
                if (isVowel(s[i])) {
                    vowelNo--;
                }
                i++;
            }
            j++;
        }

        if (maxVowel == INT_MIN)
            return 0;
        else
            return maxVowel;
    }
};
