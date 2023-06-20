// class Solution {
// public:
//     int number(int num){
//     if(num==0)return 0;   
//         // Special case. 
//         int dig = (num) - (9 * ( (num-1)/9 ));      
//         // Difference between number and largest multiple of 9 gives us digital root.
//         return dig;
        
//     }
// };
class Solution {
public:
    int addDigits(int num) {
      if(num==0)
          return 0;
      else if(num%9==0)
          return 9;
      else
          return num%9;
    }
};