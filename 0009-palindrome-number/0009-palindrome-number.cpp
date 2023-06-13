// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string s;
//         while (x!=0){
//            int a=x%10;
//             s
//             x=x/10;
//         }
        
        
//          // string s = to_string(x);

//          int left=0;
//         int right =s.length()-1;
//        while (left < right) {
//             if (s[left] != s[right])
//                 return false;
//             else
//             {
//             left++;
//             right--;
//              }
//        }

//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
         long y = 0;
        if(x<0){
            return false;
        }
        while(num>0)
        {
           int rem=num%10;
            num=num/10;
            y=y*10+rem;
        }
        cout<<y<<endl;
        if(y==x){
            return true;
            }
         return false;
    }
};