class Solution {
public:
    int fib(int n) {
       int prev= 0;
        int cur = 1;
        if ( n <2){
            return n;
        }
        for ( int i =2; i <= n ; i++){
            int a = prev + cur ;
            prev = cur;
            cur = a ;
            
        }
        return cur;
    }
};