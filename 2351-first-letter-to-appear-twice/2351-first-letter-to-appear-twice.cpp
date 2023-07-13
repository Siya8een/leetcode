class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> hash(256, 0);  // Initialize the hash table with 256 elements

        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
            if (hash[s[i]] == 2) {
                return s[i];
            }
        }

       

        return '\0';  // No repeated character found
    }
};