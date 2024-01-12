class Solution {
public:
    
    bool vowel( char a){
        if ( a=='a'|| a== 'e'|| a== 'i'|| a== 'o'|| a== 'u'|| a== 'A'|| a== 'E'|| a== 'I'|| a== 'O'|| a== 'U'){
            return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
      int n = s.length();
        int a1=0;
        int a2=0;
        
        for ( int i =0; i < n/2 ; i++){
            if(vowel(s[i])){
                a1++;
            }
            
            }
        
         for ( int i =n/2; i < n ; i++){
            if(vowel(s[i])){
                a2++;
        }
         }
        
      return a1==a2;  
        
    }
};