class Solution {
public:
    int xorOperation(int n, int start) {
        int i=0;
        int ans=0;
        
        while ( i< n){
            ans = ans ^ start;
            start= start+2;
            i++;
        }
        return ans;
    }
};