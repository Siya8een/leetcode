class Solution {
public:
    int mySqrt(int x) {
        int left =1;
        int right = x;
        while (left <= right ){
            int mid = right +( left - right )/2;
            if ( pow( mid,2)== x){
                return mid;
            }
            else if ( pow(mid,2)<x){
                left = mid+ 1;
            }
            else{
                right = mid -1;
            }
        }
        return right;
    }
};