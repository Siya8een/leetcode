class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size()<2){
            return 0;
        }
        int minel = *min_element(nums.begin(), nums.end());
        int maxel = *max_element(nums.begin(), nums.end());
        int n=0;
        int m=0;
       
      for ( int i=0;i< nums.size();i++)//first of last element is repeated exclude all those
      {
          if ( nums[i]== minel){
              n=n+1;
          }
      }
        
        for ( int i=0;i< nums.size();i++)//first of last element is repeated exclude all those
      {
          if ( nums[i]== maxel){
              m=m+1;
          }
      }
        int ans =0;
        if ( nums.size()>=(m+n))
       ans = nums.size()-n-m;
        
        if ( nums.size()<(m+n))
       ans = 0;
        
        return ans;
    }
};