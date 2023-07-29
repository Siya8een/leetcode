
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        
        if (n != t.length()) {
            return false; // If the lengths of the strings are not equal, they cannot be isomorphic.
        }
        
        unordered_map<char, char> sToT; // Map to store the mapping from characters in s to characters in t
        unordered_map<char, char> tToS; // Map to store the mapping from characters in t to characters in s
        
        for (int i = 0; i < n; i++) {
            char charS = s[i];
            char charT = t[i];
            
            if (sToT.find(charS) == sToT.end() && tToS.find(charT) == tToS.end()) {
                // If both characters are not in the maps, add them to the maps.
                sToT[charS] = charT;
                tToS[charT] = charS;
            } else {
                // If either of the characters is already in the map, check if the mapping is valid.
                if (sToT[charS] != charT || tToS[charT] != charS) {
                    return false;
                }
            }
        }
        
        return true; // If all characters are correctly mapped, the strings are isomorphic.
    }
};
