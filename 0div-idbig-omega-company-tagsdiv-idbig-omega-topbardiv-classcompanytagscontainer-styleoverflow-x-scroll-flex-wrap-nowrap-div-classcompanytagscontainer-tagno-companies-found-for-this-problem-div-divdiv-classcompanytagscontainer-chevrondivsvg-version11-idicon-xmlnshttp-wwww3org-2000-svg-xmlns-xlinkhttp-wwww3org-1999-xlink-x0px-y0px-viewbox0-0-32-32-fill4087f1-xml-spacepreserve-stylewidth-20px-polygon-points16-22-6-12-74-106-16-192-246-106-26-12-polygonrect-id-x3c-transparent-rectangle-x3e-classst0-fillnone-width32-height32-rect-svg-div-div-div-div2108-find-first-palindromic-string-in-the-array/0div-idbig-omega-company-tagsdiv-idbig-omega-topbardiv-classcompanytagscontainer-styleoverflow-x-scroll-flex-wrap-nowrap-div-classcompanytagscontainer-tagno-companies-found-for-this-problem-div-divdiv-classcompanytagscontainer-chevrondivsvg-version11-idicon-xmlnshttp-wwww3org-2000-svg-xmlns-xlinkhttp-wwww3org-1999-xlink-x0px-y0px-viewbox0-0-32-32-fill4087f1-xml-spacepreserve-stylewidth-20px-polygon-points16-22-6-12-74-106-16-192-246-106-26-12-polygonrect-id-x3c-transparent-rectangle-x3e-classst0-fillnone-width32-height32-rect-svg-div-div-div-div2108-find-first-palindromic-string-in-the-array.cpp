class Solution {
public:
    bool ispali(string a) {
        int i = 0; 
        int j = a.size() - 1;
        while (i <= j) {
            if (a[i] != a[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true; // Return true if the loop completes without finding any non-matching characters
    }

    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (ispali(words[i])) {
                ans = words[i];
                break;
            }
        }
        return ans;
    }
};
