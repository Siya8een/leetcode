#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPredecessor(const string& wordA, const string& wordB) {
        if (wordA.size() + 1 != wordB.size())
            return false;
        
        int i = 0, j = 0;
        bool foundDifference = false;
        while (i < wordA.size() && j < wordB.size()) {
            if (wordA[i] != wordB[j]) {
                if (foundDifference)
                    return false;
                foundDifference = true;
                j++; // Move to the next character in wordB
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> arr(n, 1);
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i]) && arr[i] < arr[j] + 1) {
                    arr[i] = arr[j] + 1;
                }
            }
        }
        
        int maxarr = 1;
        for (int i = 0; i < n; i++) {
            maxarr = max(maxarr, arr[i]);
        }
        return maxarr;
    }
};
