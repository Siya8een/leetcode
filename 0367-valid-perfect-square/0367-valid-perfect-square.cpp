class Solution {
public:
    bool isPerfectSquare(int num) {
         int left =1;
        int right = num;
        while (left <= right ){
            int mid = right +( left - right )/2;
            if ( pow( mid,2)== num){
                return true;
            }
            else if ( pow(mid,2)<num){
                left = mid+ 1;
            }
            else{
                right = mid -1;
            }
        }
        return false;
    }
    
};

