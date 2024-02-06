class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            hashTable[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& it : hashTable) {
            result.push_back(it.second);
        }
        return result;
    }
};