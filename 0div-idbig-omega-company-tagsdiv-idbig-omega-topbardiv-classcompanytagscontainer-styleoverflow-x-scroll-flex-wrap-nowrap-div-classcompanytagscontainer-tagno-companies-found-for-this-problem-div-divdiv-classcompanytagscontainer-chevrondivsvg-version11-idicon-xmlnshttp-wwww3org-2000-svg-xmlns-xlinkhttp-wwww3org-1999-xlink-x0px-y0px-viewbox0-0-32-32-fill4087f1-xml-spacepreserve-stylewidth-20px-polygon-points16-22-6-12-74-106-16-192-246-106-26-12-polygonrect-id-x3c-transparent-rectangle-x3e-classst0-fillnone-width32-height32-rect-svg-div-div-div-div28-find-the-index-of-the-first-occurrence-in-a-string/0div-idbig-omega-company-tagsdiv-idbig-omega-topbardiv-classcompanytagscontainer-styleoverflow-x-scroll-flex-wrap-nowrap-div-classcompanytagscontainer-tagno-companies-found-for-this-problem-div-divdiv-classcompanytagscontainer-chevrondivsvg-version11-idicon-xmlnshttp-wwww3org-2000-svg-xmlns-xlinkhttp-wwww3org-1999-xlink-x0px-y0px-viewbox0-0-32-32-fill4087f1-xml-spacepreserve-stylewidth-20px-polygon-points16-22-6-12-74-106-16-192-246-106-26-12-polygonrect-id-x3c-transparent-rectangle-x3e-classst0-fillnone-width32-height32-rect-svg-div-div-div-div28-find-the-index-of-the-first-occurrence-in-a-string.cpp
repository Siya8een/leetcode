#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if ( haystack.length() < needle.length()){
            return -1;
        }
         if ( haystack.length() == needle.length()){
            if ( haystack == needle){
                return 0;
            }
             else {
                 return -1;
             }
        }
        char ch = needle[0];
        int a = needle.size();
        int ans = 0;

        for (int i = 0; i <= haystack.length() - a; i++) {
            if (ch == haystack[i] && haystack.substr(i, a) == needle) {
                ans = i;
                return ans;
            }
        }

        return -1;
    }
};
