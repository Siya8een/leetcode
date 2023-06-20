class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c);
        if(c<0){
            return false;
        }
        while(a<=b){
            if(a*a+b*b==c){
                return true;
                break;
            }
            else if(a*a+b*b<c){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};