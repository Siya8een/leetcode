class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";

        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                ans = num.substr(0,i+1);
                break; // Exit the loop once the first odd digit is found
            }
        }

        return ans;
    }
};
