class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum= 0;
        int sum1=0;
        for (int i=0;i<gain.size();i++){
            sum1 = sum1 + gain[i];
            
                sum = max ( sum, sum1);
               
        }
        return sum;
    }
};
