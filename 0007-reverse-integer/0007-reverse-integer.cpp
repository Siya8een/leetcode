class Solution {
public:
    int reverse(int x) {
        long reverse = 0;
        while(x!=0){
            int a = x%10;
            reverse = reverse*10 + a;
            x=x/10;
        }
        //to check in range 
       if(reverse>INT_MAX || reverse<INT_MIN) {
           return 0;
       }
        
    
        return reverse;
        
        
    }
};