#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hashmapS(26, 0);
        for (int i = 0; i < s.length(); i++) {
            hashmapS[s[i] - 'a']++;
        }
        vector<int> hashmapT(26, 0);
        for (int i = 0; i < t.length(); i++) {
            hashmapT[t[i] - 'a']++;
        }
        char ans;
        for (int i = 0; i < 26; i++) {
            int x = hashmapT[i] - hashmapS[i];
            cout << abs(x) << endl;
            if (abs(x) == 1) {
                ans = i + 'a';
                return ans;
            }
        }
        return ans;
    }
};
