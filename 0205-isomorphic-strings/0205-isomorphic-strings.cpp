class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if(s.size()!= t.size()) return false;
        map<char, char> mpp;

        for(int i=0; i<n; i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                if(mpp[s[i]]==t[i]) continue;
                else return false;
            }
            // else mpp[s[i]] = t[i];
            else
            {
                for(auto it:mpp)
                {
                    if(it.second == t[i]) return false;
                    else continue;
                }
                mpp[s[i]] = t[i];
            }
        }
        return true;       
    }
};