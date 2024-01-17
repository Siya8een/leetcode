class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for (auto num : arr) {
            mpp[num]++;
        }

        unordered_set<int> occurrenceSet;

        for (const auto& pair : mpp) {
            if (!occurrenceSet.insert(pair.second).second) {
                // If insertion fails, it means there was already an occurrence of the same count
                return false;
            }
        }

        return true;
    }
};
