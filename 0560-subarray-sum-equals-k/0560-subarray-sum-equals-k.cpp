class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> a;
         int count =0;
        int sum=0;
        for ( int i=0 ;i < nums.size(); i++){
             sum = sum + nums[i];
             if ( sum== k){
                 count++;
             }
            int rem = sum - k;
             if ( a.find ( rem) != a.end ()){
                 count= count + a[rem];
             }
            a[sum ]++;
        }
         return count;
    }
};