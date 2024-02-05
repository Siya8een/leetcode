class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKindex =-1;
        int maxKindex = -1;
        int culprit = -1 ;
        int i =0;
        long long ans =0;
         while ( i < nums.size()){
             if (nums[i]< minK || nums[i]> maxK){
                 culprit = i;
             }
             if ( nums[i] == minK ){
                minKindex =i; 
             }
              if ( nums[ i ]== maxK){
                  maxKindex =i;
              }
             int smaller= min (maxKindex ,minKindex );
              int temp  = -culprit + smaller ;
             if ( temp >= 0){
                 ans = ans + temp;
             }
             i++;
         }
        return ans ;
    }
};