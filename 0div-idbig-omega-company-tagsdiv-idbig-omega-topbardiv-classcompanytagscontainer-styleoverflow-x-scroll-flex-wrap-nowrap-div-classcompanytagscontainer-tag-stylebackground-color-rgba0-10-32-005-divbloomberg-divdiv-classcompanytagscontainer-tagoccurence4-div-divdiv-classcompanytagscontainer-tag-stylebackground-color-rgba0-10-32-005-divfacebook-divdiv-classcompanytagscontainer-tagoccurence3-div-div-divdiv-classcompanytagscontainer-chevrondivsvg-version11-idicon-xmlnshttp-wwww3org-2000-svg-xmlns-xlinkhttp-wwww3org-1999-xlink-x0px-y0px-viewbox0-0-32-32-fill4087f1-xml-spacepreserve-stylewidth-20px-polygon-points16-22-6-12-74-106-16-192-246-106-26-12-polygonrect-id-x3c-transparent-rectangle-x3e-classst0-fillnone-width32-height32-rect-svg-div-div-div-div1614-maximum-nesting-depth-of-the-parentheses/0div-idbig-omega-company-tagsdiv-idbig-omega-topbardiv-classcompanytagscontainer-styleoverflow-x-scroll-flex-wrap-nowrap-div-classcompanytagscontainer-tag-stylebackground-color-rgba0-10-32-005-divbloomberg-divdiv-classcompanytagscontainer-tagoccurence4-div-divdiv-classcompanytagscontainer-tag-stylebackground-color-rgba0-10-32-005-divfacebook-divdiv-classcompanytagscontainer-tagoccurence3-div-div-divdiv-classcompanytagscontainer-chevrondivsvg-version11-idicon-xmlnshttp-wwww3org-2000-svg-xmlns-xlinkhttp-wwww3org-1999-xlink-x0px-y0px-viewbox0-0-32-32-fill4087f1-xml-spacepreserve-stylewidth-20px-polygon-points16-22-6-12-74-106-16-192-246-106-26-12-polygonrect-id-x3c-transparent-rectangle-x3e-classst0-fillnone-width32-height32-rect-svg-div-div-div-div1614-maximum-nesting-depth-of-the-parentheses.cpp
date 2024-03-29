class Solution {
public:
    int maxDepth(string s) {
        stack < char > st ;
        int ans=0;
        for ( int i =0; i < s.length(); i++){
            if ( s[i] == '('){
                st.push(s[i]);
            }
            if ( s[i] == ')'){ // Corrected condition
                st.pop();
            }
           if ( st.size()> ans){
                ans = st.size();
           }
        }
        return ans;
    }
};
