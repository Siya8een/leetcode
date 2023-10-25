class Solution {
public:
    int sum( vector <int>& weights){
         int ans =0;
         for ( int i =0 ; i < weights.size();i++){
             ans = ans + weights[i];
         }
         return ans ;
     }
    
   int canship(int mid ,vector<int>& weights, int days){
        int currentCapacity = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (currentCapacity + weight > mid) {
                requiredDays++;
                currentCapacity = 0;
            }
            currentCapacity += weight;
        }

        return requiredDays <= days;
   }
    
   
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end()); 
        int end = sum( nums);
        while ( start < end ){
             int mid = start + (end - start) / 2;
            if ( canship(mid , nums, k )){
                 end = mid;
            }
            else {
                start = mid +1;
            }
        }
        return start;
    }
};