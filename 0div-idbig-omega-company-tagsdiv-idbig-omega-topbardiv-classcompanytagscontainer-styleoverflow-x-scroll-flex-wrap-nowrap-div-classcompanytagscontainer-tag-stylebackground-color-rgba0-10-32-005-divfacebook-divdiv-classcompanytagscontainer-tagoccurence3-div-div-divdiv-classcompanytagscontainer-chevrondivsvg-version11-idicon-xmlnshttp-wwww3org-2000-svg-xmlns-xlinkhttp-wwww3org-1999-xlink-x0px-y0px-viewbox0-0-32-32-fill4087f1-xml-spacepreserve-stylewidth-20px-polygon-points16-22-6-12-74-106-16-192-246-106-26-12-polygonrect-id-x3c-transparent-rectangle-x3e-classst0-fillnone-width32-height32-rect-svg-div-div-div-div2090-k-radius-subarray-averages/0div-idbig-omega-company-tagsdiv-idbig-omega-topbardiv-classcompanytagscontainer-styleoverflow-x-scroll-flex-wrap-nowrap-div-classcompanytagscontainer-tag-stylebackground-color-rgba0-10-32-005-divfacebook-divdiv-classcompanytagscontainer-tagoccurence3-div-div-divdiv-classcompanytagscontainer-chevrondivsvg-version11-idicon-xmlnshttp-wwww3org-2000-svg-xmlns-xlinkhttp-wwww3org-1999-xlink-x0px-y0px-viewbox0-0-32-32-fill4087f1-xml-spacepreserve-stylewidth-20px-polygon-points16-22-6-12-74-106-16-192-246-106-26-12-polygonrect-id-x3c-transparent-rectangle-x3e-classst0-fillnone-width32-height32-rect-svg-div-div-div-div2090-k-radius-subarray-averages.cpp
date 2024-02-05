class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if ( k ==0 ){
             return nums ;
        }
        int n = nums.size();
        
         vector<long long> acc_sum(nums.size(), 0);
        vector<int> ans(nums.size(), -1);
        if ( n < (2*k + 1)){
            return ans ;
        }
       

        acc_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            acc_sum[i] = acc_sum[i - 1] + nums[i];
        }
        
        
        
        
        int j = k;

        while (j < nums.size() - k) {
          ans[j] = (acc_sum[j + k] - (j - k - 1 >= 0 ? acc_sum[j - k - 1] : 0)) / static_cast<int64_t>(2 * k + 1);

            j++;
        }

        return ans;
    }
};
