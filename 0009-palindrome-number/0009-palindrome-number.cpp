class Solution {
public:
    bool isPalindrome(int x) {
        // String s;
        // while (x!=0){
        //    int a=x%10;
        //     s<< a;
        //     x=x/10;
        // }
        
        
         string s = to_string(x);

         int left=0;
        int right =s.length()-1;
       while (left < right) {
            if (s[left] != s[right])
                return false;
            else
            {
            left++;
            right--;
             }
       }

        return true;
    }
};