class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        
        // Split the string s into words
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        
        // Check if the pattern and words have the same length
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // Process each character-word pair
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string word = words[i];
            
            // Check if the character is already mapped to a different word or vice versa
            if (charToWord.count(c) && charToWord[c] != word) {
                return false;
            }
            if (wordToChar.count(word) && wordToChar[word] != c) {
                return false;
            }
            
            // Establish the bijection between the character and word
            charToWord[c] = word;
            wordToChar[word] = c;
        }
        
        return true;
    }
};
