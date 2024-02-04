class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if (n < t.length()) {
            return "";
        }

        unordered_map<char, int> mpp;
        for (char ch : t) {
            mpp[ch]++;
        }

        int requiredCount = t.length();
        int i = 0, j = 0;
        int min_window_size = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];
            if (mpp[ch] > 0) {
                requiredCount--;
            }
            mpp[ch]--;

            while (requiredCount == 0) {
                int cur_min_window_size = j - i + 1;
                if (min_window_size > cur_min_window_size) {
                    min_window_size = cur_min_window_size;
                    start_i = i;
                }

                if (mpp[s[i]] == 0) {
                    requiredCount++;
                }
                mpp[s[i]]++;
                i++;
            }
            j++;
        }

        if (min_window_size == INT_MAX) {
            return "";
        }

        return s.substr(start_i, min_window_size);
    }
};
