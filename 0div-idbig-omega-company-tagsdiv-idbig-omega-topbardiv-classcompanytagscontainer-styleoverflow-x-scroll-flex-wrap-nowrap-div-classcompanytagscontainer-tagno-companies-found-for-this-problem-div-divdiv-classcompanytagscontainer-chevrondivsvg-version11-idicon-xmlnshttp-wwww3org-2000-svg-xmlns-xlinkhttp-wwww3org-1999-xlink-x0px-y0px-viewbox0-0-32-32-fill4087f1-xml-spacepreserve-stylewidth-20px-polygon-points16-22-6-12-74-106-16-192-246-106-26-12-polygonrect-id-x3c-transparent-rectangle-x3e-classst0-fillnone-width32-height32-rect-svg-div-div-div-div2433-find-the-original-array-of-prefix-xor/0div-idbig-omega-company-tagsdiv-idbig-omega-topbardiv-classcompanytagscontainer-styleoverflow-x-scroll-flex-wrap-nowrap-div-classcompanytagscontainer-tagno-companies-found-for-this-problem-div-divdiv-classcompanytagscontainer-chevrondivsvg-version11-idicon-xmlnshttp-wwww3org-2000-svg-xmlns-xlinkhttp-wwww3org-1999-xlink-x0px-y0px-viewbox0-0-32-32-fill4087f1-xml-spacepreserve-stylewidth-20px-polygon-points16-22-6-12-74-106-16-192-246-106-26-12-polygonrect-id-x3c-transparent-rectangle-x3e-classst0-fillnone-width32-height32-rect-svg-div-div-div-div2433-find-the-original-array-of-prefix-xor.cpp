class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector <int> ans ;
        for ( int i = pref.size()-1; i>0;i--){
            int x = (pref[i]^pref[i-1]);
         ans .push_back( x);
        }
        ans .push_back( pref[0]);
        reverse( ans.begin(), ans.end());
    
         return ans;
    }
};