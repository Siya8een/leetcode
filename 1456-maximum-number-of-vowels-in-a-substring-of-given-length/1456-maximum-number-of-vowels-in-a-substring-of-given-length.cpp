class Solution {
public:
    bool isVowel ( char ch ){
         if ( ch == 'a'||ch == 'e' ||ch == 'i'||ch ==  'o'||ch ==  'u' ){
             return true ;
         }
        else 
            return false ;
    }
    int maxVowels(string s, int k) {
        int maxVowel = INT_MIN;
        int vowelNo =0;
        //
        int i =0;
        int j =0;
        
        while ( j < s.length()){
            if ( isVowel(s[j])){
                vowelNo++;
            }
            if ( j -i+1 == k ){
                if ( maxVowel <= vowelNo){
                    maxVowel = vowelNo;
                }
                 if (isVowel(s[i])) {
                    vowelNo--;
                }
                i++;
            }
            j++;
        }
        if (maxVowel == INT_MIN)
        return 0;
        else {
             return maxVowel;
        }
    }
};