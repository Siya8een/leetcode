class Solution {
public:
    std::function<bool(const pair<char, int>&, const pair<char, int>&)> lambda =
        [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Sort in descending order of frequency
        };

    string frequencySort(string s) {
        map<char,int> mpp;
        string ans;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        } 
        vector<pair<char,int>> helper;
        for(auto it : mpp) {
            helper.push_back({it.first,it.second});
        } 
        sort(helper.begin(), helper.end(), lambda);

        for(auto it : helper) {
            ans.append(it.second, it.first); // Append characters according to their frequency
        } 

        return ans;
    }
};