class Solution {
public:
    string countAndSay(int n) {
        if ( n==1){
            return "1";
        }
          if ( n==2){
            return "11";
        }
         string s = countAndSay(n - 1);
        int cnt = 1;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() && s[i] == s[i + 1]) {
                cnt++;
            } else {
               ans += char(cnt + '0');
                ans += s[i]; 
                cnt = 1;
            }
        }
        return ans;
    }
};