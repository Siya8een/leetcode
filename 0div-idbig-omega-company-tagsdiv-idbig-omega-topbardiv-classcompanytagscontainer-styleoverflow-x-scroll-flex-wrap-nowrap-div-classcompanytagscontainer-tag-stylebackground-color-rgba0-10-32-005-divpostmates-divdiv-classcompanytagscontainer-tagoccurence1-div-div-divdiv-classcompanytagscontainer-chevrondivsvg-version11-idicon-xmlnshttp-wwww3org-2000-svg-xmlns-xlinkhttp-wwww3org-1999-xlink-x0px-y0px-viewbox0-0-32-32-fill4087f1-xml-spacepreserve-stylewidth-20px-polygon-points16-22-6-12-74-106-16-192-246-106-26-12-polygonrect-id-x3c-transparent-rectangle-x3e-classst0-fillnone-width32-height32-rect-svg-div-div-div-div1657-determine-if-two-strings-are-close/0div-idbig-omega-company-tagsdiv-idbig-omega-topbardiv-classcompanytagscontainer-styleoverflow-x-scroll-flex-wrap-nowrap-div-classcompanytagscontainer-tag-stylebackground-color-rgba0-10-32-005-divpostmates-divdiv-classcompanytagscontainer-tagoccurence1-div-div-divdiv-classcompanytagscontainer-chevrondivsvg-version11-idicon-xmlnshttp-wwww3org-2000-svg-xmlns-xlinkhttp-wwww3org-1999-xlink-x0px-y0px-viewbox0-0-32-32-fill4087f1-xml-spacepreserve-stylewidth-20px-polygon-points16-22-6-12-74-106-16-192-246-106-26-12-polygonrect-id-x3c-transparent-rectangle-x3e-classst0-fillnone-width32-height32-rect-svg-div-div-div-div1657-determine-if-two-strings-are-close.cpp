#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::unordered_map<char, int> freq1, freq2;
        std::unordered_set<char> charSet1, charSet2;

        for (char ch : word1) {
            freq1[ch]++;
            charSet1.insert(ch);
        }

        for (char ch : word2) {
            freq2[ch]++;
            charSet2.insert(ch);
        }

        // Check if the sets of characters are the same
        if (charSet1 != charSet2) {
            return false;
        }

        // Create vectors to store frequencies for both words
        std::vector<int> freqVec1, freqVec2;
        for (const auto& entry : freq1) {
            freqVec1.push_back(entry.second);
        }

        for (const auto& entry : freq2) {
            freqVec2.push_back(entry.second);
        }

        // Sort the frequencies vectors
        std::sort(freqVec1.begin(), freqVec1.end());
        std::sort(freqVec2.begin(), freqVec2.end());

        // Check if the sorted frequencies vectors are the same
        return freqVec1 == freqVec2;
    }
};
