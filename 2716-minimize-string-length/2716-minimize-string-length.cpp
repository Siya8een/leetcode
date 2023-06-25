class Solution {
public:
    int minimizedStringLength(string s) {
      // return only the unique elements of the string 
        int count =0;
        sort(s.begin(), s.end());
        for ( int i=0; i< s.length(); i++){
            if (s[i]!= s[i+1]){
                count ++;
            }
            
        }
        return count;
    }
    
};