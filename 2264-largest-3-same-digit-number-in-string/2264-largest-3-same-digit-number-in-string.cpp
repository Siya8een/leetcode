class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = '\0';
        int idx = -1;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (num[i] > ch) {
                    ch = num[i];
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            return "";
        }
        return num.substr(idx, 3);
    }
};
