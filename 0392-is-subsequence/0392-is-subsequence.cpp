class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        string ans ;
        while ( i< s.length() && j< t.length()){
            if ( s[i]== t[j]){
                ans . push_back(s[i]);
                i++;
                j++;
                
            }
            else {
                j++;
            }
        }
        return ans == s;
    }
};