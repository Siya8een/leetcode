#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }
        
        std::vector<std::pair<char, int>> frequencyPairs;
        for (auto it : mpp) {
            frequencyPairs.push_back(it);
        }
        
        // Custom sort based on frequency
        std::sort(frequencyPairs.begin(), frequencyPairs.end(), 
                  [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                      return a.second > b.second; // Sort by frequency in descending order
                  });
        
        std::string ans = "";
        for (auto& pair : frequencyPairs) {
            for (int i = 0; i < pair.second; ++i) {
                ans.push_back(pair.first);
            }
        }
        
        return ans;
    }
};
