class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR=0;
        for ( int i=0;i < s.length();i++){
            XOR = XOR ^ (int)s[i];
        }
        for ( int i=0;i < t.length();i++){
            XOR = XOR ^ (int)t[i];
        }
         return (char)XOR;
    }
};