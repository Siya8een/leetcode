class Solution {
public:
    bool allelement0( vector < int>& mpp){
        for (int &i : mpp) { // Corrected the condition
            if (i != 0)
                return false;
        }
        return true;
    }
      
    vector<int> findAnagrams(string s, string p) {
        vector < int > ans ;
        if ( p.length()> s.length()){
            return ans ;
        }
        vector < int > mpp( 26 , 0);
        for ( int i =0; i < p.length();i++){
            mpp[p[i]-'a']++;
        }
        int reqTarget = p.length();
        int i =0; 
        int j =0;
        while ( j < s.length()){
           mpp[s[j]-'a']--;
            if (j-i + 1 == p.length()){
                if ( allelement0(mpp)){
                    ans.push_back( i);
                }
                mpp[s[i] - 'a']++; // Corrected the character to be incremented
                i++;
            }
            j++;
        }
        return ans;
    }
};

