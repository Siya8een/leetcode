class Solution {
public:
    string countAndSay(int n) {
        if (n==1){
            return "1";
        }
        if (n==2){
            return "11";
        }
        
        string s = countAndSay(n-1);
        string ans;
        int count =1;
        for ( int i=0; i < s.size();i++){
            
            if ( s[i]==s[i+1] && i < s.size()){
                count++;
            }
            else {
           ans += ( count +  '0');
             ans += s[i]; 
            count =1;
            }
            
        }
        return ans;
    }
};