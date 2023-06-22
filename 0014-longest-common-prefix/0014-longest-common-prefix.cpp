class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Check if the input vector is empty
        if (strs.empty()) {
            return "";
        }
        
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char a = strs[0][i];
            bool match = true;
            
            for (int j = 1; j < strs.size(); j++) {
                // Check if the index is within the string size
                if (i >= strs[j].size() || strs[j][i] != a) {
                    match = false;
                    break;
                }
            }
            
            if (!match) {
                break;
            } else {
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};
