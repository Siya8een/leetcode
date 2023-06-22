class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // to find the longest common prefix
        string ans = "";
        
        int m = strs[0].length();
        for ( int i=0;i < m; i++){
            
            char ch = strs[0][i];
            bool match = true;
            for ( int j=1;j< strs.size(); j++){
                if (  i>=strs[j].size()  ||  strs[j][i]!=ch ){
                    //  if (i >= strs[j].size() || strs[j][i] != a) 
                    match = false;
                    break;
                }
               
            }
            if (!match) {
                break;
            } else {
                ans.push_back(ch);
            }
            
        }
        return ans;
    }
};